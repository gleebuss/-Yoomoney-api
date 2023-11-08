#include "Operation_history.hpp"
#include "Exception.hpp"

nlohmann::json Operation_history::req() {
    std::string url = "https://yoomoney.ru/api/" + method;

    auto payload = cpr::Payload{};

    if (!this->type.empty()) payload.Add({"type", type});
    if (!this->label.empty()) payload.Add({"label", label});
    if (!this->from.empty()) payload.Add({"from", from});
    if (!this->till.empty()) payload.Add({"till", till});
    if (this->start_record >= 0) payload.Add({"start_record", std::to_string(start_record)});
    if (this->records >= 0) payload.Add({"records", std::to_string(records)});
    payload.Add({"details", "true"});

    cpr::Response r = cpr::Post(cpr::Url{url},
                                cpr::Bearer{this->api_key},
                                cpr::Header{{"Content-Type", "application/x-www-form-urlencoded"}},
                                payload);

    return nlohmann::json::parse(r.text);
};

Operation_history::Operation_history(std::string api_key, std::string method, std::string type, std::string label,
                                     std::string from, std::string till, int start_record, int records) {
    this->api_key = api_key;
    this->method = method;

    this->type = type;
    this->label = label;
    this->from = from;
    this->till = till;
    this->start_record = start_record;
    this->records = records;

    auto data = this->req();

    if (data.contains("error")) {
        if (data["error"] == "illegal_param_type") throw IllegalParamType();
        else if (data["error"] == "illegal_param_start_record") throw IllegalParamStartRecord();
        else if (data["error"] == "illegal_param_records") throw IllegalParamRecords();
        else if (data["error"] == "illegal_param_label") throw IllegalParamLabel();
        else if (data["error"] == "illegal_param_from") throw IllegalParamFromDate();
        else if (data["error"] == "illegal_param_till") throw IllegalParamTillDate();
        else throw Technical();
    }
    if (data.contains("next_record")) this->next_record = data["next_record"];

    if (!data["operations"].empty()) {
        for (auto i: data["operations"]) {
            Operations tmp = Operations();

            tmp.amount = i.contains("amount") ? to_string(i["amount"]) : "NONE";
            tmp.operation_id = i.contains("operation_id") ? i["operation_id"] : "NONE";
            tmp.status = i.contains("status") ? i["status"] : "NONE";
            tmp.datetime = i.contains("datetime") ? i["datetime"] : "NONE";
            tmp.title = i.contains("title") ? i["title"] : "NONE";
            tmp.pattern_id = i.contains("pattern_id") ? i["pattern_id"] : "NONE";
            tmp.direction = i.contains("direction") ? i["direction"] : "NONE";
            tmp.label = i.contains("label") ? i["label"] : "NONE";
            tmp.type = i.contains("type") ? i["type"] : "NONE";
            tmp.amount_due = i.contains("amount_due") ? to_string(i["amount_due"]) : "NONE";
            tmp.fee = i.contains("fee") ? to_string(i["fee"]) : "NONE";
            tmp.sender = i.contains("sender") ? i["sender"] : "NONE";
            tmp.recipient = i.contains("recipient") ? i["recipient"] : "NONE";
            tmp.recipient_type = i.contains("recipient_type") ? i["recipient_type"] : "NONE";

            this->operations.push_back(tmp);
        }
    }
};

std::string Operation_history::getNextRecord() {
    return next_record;
}

const std::vector<Operation_history::Operations> Operation_history::getOperations() const {
    return operations;
};

const std::string &Operation_history::Operations::getOperationId() const {
    return operation_id;
}

const std::string &Operation_history::Operations::getStatus() const {
    return status;
}

const std::string &Operation_history::Operations::getDatetime() const {
    return datetime;
}

const std::string &Operation_history::Operations::getTitle() const {
    return title;
}

const std::string &Operation_history::Operations::getPatternId() const {
    return pattern_id;
}

const std::string &Operation_history::Operations::getDirection() const {
    return direction;
}

const std::string &Operation_history::Operations::getAmount() const {
    return amount;
}

const std::string &Operation_history::Operations::getLabel() const {
    return label;
}

const std::string &Operation_history::Operations::getType() const {
    return type;
}

const std::string &Operation_history::Operations::getAmountDue() const {
    return amount_due;
}

const std::string &Operation_history::Operations::getFee() const {
    return fee;
}

const std::string &Operation_history::Operations::getSender() const {
    return sender;
}

const std::string &Operation_history::Operations::getRecipient() const {
    return recipient;
}

const std::string &Operation_history::Operations::getRecipientType() const {
    return recipient_type;
}
