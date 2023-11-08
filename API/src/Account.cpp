#include "Account.hpp"
#include <iostream>

Account::Account(const std::string api_key, const std::string method) {
    this->api_key = api_key;
    this->method = method;

    auto data = req();

    if (data.size() != 0) {
        this->account = data["account"];
        this->balance = std::to_string(data["balance"].get<float>());
        this->currency = data["currency"];
        this->account_status = data["account_status"];
        this->account_type = data["account_type"];

        if (data.contains("balance_details")) {
            if (data["balance_details"].contains("total"))
                this->total = std::to_string(data["balance_details"]["total"].get<float>());
            if (data["balance_details"].contains("available"))
                this->available = std::to_string(data["balance_details"]["available"].get<float>());
            if (data["balance_details"].contains("deposition_pending"))
                this->deposition_pending = std::to_string(data["balance_details"]["deposition_pending"].get<float>());
            if (data["balance_details"].contains("blocked"))
                this->blocked = std::to_string(data["balance_details"]["blocked"].get<float>());
            if (data["balance_details"].contains("debt"))
                this->debt = std::to_string(data["balance_details"]["debt"].get<float>());
            if (data["balance_details"].contains("hold"))
                this->hold = std::to_string(data["balance_details"]["hold"].get<float>());
        }

        if (data.contains("cards_linked")) {
            Card tmp;
            if (data["cards_linked"].contains("pan_fragment"))
                tmp.pan_fragment = data["cards_linked"]["pan_fragment"];
            if (data["cards_linked"].contains("type"))
                tmp.type = data["cards_linked"]["type"];
            cards.push_back(tmp);
        }
    }
};

nlohmann::json Account::req() {
    std::string url = "https://yoomoney.ru/api/" + method;

    cpr::Response r = cpr::Get(cpr::Url{url},
                               cpr::Bearer{this->api_key},
                               cpr::Header{{"Content-Type", "application/x-www-form-urlencoded"}});

    return nlohmann::json::parse(r.text);
};

std::string Account::bool_to_str(bool flag) {
    return flag ? "true" : "false";
}

const std::string &Account::Card::getPanFragment() const {
    return pan_fragment;
}

const std::string &Account::Card::getType() const {
    return type;
}
