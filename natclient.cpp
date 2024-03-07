//
// Created by Kina on 2024/3/7.
//
#include <pjlib.h>
#include <pjlib-util.h>
#include <pjnath.h>

void on_nat_detect(pj_stun_nat_detect_result *result) {
    if (result->status != PJ_SUCCESS) {
        pj_perror(4, "Error", result->status, "NAT detection failed");
    } else {
        printf("NAT type is %s\n", pj_stun_get_nat_name(result->nat_type));
    }
}

int main() {
    pj_caching_pool cp;
    pj_pool_t *pool;
    pj_thread_t *thread;
    pj_stun_nat_detect_param param;
    pj_status_t status;

    // 初始化PJLIB
    status = pj_init();
    PJ_ASSERT_RETURN(status == PJ_SUCCESS, 1);

    pj_caching_pool_init(&cp, &pj_pool_factory_default_policy, 0);
    pool = pj_pool_create(&cp.factory, "nat", 512, 512, NULL);

    // 必须创建PJLIB工具线程
    pj_thread_create(pool, "nat", &pj_ioqueue_poll, NULL, 0, 0, &thread);

    // 设置NAT检测参数
    pj_stun_nat_detect_param_default(&param);
    param.pool = pool;
    param.cb = on_nat_detect;
    param.srv = pj_str("stun.l.google.com:19302"); // 使用Google的公共STUN服务器

    // 执行NAT类型检测
    status = pj_stun_detect_nat_type(&param);
    PJ_ASSERT_RETURN(status == PJ_SUCCESS, 1);

    // 等待NAT检测完成
    pj_thread_sleep(10000);

    pj_pool_release(pool);
    pj_caching_pool_destroy(&cp);
    pj_shutdown();

    return 0;
}

#include "natclient.h"
