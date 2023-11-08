#include "QuickPay.hpp"
#include <iostream>

QuickPay::QuickPay(std::string api_key,
                   std::string receiver,
                   std::string sum) {
    this->api_key = api_key;
    this->receiver = receiver;
    this->sum = sum;
};

cpr::Url QuickPay::get_url() {
    return this->req(this->receiver, this->sum);
};

cpr::Url QuickPay::req(std::string receiver,
                       std::string sum) {
    std::string url = "https://yoomoney.ru/quickpay/confirm.xml";

    cpr::Response r = cpr::Post(cpr::Url{url},
                                cpr::Bearer{this->api_key},
                                cpr::Header{{"Content-Type", "application/x-www-form-urlencoded"}},
                                cpr::Payload{{"receiver",      receiver},
                                             {"quickpay-form", "button"},
                                             {"sum",           sum}});

    return r.url;
}
