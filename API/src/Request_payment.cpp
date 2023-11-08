#include "Request_payment.hpp"
#include <iostream>

nlohmann::json Request_payment::req(std::string to,
                                    std::string amount,
                                    std::string comment,
                                    std::string message,
                                    std::string label) {
    std::string url = "https://yoomoney.ru/api/" + method;

    cpr::Response r = cpr::Post(cpr::Url{url},
                                cpr::Bearer{this->api_key},
                                cpr::Header{{"Content-Type", "application/x-www-form-urlencoded"}},
                                cpr::Payload{{"pattern_id", "p2p"},
                                             {"to",         to},
                                             {"amount",     amount},
                                             {"comment",    comment},
                                             {"message",    message},
                                             {"label",      label}});
    return nlohmann::json::parse(r.text);
};

Request_payment::Request_payment(std::string api_key, std::string method,
                                 std::string to,
                                 std::string amount,
                                 std::string comment,
                                 std::string message,
                                 std::string label) {
    this->api_key = api_key;
    this->method = method;

    auto data = req(to, amount, comment, message, label);
    status = data["status"];

    if (status == "success") {
        request_id = data["request_id"];
        contract_amount = std::to_string(data["contract_amount"].get<float>());
        balance = std::to_string(data["balance"].get<float>());
//        fees = std::to_string(data["fees"]["service"].get<float>());
    } else {
        if (data.contains("error_description"))
            std::cout << data["error_description"];
        throw data["error"];
    }
}
