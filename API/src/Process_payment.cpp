#include "Process_payment.hpp"

Process_payment::Process_payment(std::string api_key, std::string method,
                                 std::string request_id) {
    this->api_key = api_key;
    this->method = method;
    this->request_id = request_id;
    auto data = req();

    status = data["status"];

    if (status == "success") {
        payer = data["payer"];
        payee = data["payee"];
        balance = std::to_string(data["balance"].get<float>());
        credit_amount = std::to_string(data["credit_amount"].get<float>());
    } else {
        if (data.contains("error_description"))
            std::cout << data["error_description"];
        throw data["error"];
    }
}

nlohmann::json Process_payment::req() {
    std::string url = "https://yoomoney.ru/api/" + method;

    cpr::Response r = cpr::Post(cpr::Url{url},
                                cpr::Bearer{this->api_key},
                                cpr::Header{{"Content-Type", "application/x-www-form-urlencoded"}},
                                cpr::Payload{{"request_id", this->request_id}});
    std::cout << " ";
    return nlohmann::json::parse(r.text);
}
