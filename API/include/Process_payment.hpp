#include "cpr/cpr.h"
#include "dependencies/json.hpp"
#include "iostream"


/// \class Process_payment
/// \brief Класс, позволяющий подтвердить ранее созданный платеж
class Process_payment {
private:
    Process_payment() = default;

    ///Ключ для получения доступа к API
    /// \var api_key
    std::string api_key;

    ///Название метода для подтверждения ранее созданного платежа
    /// \var method
    std::string method;

    ///Идентификатор запроса
    /// \var request_id
    std::string request_id;

    ///Код результата выполнения операции
    /// \var status
    std::string status;

    ///Баланс счета пользователя после проведения платежа
    /// \var balance
    std::string balance;

    ///Номер счета плательщика
    /// \var payer
    std::string payer;

    ///Номер счета получателя
    /// \var payer
    std::string payee;

    ///Сумма, поступившая на счет получателя
    /// \var payer
    std::string credit_amount;

    nlohmann::json req();

public:
    /// Создает экземпляр класса Process_payment, нужен для подтверждения платежа
    /// \param api_key API ключ для доступа к операции
    /// \param method Название метода в URL
    /// \param request_id Идентификатор запроса
    Process_payment(std::string api_key, std::string method, std::string request_id);

    ///
    /// \return код результата выполнения операции
    std::string get_status() {
        return status;
    };

    ///
    /// \return идентификатор запроса
    std::string get_request_id() {
        return request_id;
    };

    ///
    /// \return номер счета плательщика
    std::string get_payer() {
        return payer;
    };

    ///
    /// \return баланс счета пользователя после проведения платежа
    std::string get_balance() {
        return balance;
    };

    ///
    /// \return номер счета получателя
    std::string get_payee() {
        return payee;
    };

    ///
    /// \return сумма, поступившую на счет получателя
    std::string get_credit_amount() {
        return credit_amount;
    };

};