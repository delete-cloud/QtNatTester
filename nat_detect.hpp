//
// Created by Kina on 2024/3/9.
//

#ifndef NATTYPETEST_NAT_DETECT_HPP
#define NATTYPETEST_NAT_DETECT_HPP

#include "juice/juice.h"

class nat_detect {
public:
    nat_detect() {
        (&config);
    }
    void on_nat_detect();

private:
    juice_agent_t *agent;
    juice_config config;
};

void nat_detect::on_nat_detect() {

}

#endif //NATTYPETEST_NAT_DETECT_HPP
