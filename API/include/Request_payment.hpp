#include "cpr/cpr.h"
#include "dependencies/json.hpp"


/// \class Request_payment
/// \brief Класс, позволяющий создать платеж
class Request_payment {
private:
    Request_payment() = default;

    ///Ключ для получения доступа к API
    /// \var api_key
    std::string api_key;

    ///Название метода для создания платежа
    /// \var method
    std::string method;

    /// Код результата выполнения операции
    /// \var status
    std::string status;

    /// Идентификатор запроса платежа. Присутствует только при успешном выполнении метода.
    /// \var request_id
    std::string request_id;

    /// Код ошибки при проведении платежа
    /// \var error
    std::string error;

    ///	Сумма к списанию со счета в валюте счета плательщика (столько заплатит пользователь вместе с комиссией).
    /// \var contract_amount
    std::string contract_amount;

    /// Текущий баланс счета пользователя
    /// \var balance
    std::string balance;

    nlohmann::json req(std::string to,
                       std::string amount,
                       std::string comment,
                       std::string message,
                       std::string label
    );

public:
    /// Создает экземпляр класса Request_payment, нужен для создания платежа
    /// \param api_key API ключ для доступа к операции
    /// \param method Название метода в URL
    /// \param to Идентификатор получателя перевода
    /// \param amount Сумма к оплате (столько заплатит отправитель)
    /// \param comment Комментарий к переводу, отображается в истории отправителя
    /// \param message Комментарий к переводу, отображается получателю
    /// \param label Метка платежа
    Request_payment(std::string api_key, std::string method,
                    std::string to,
                    std::string amount,
                    std::string comment,
                    std::string message,
                    std::string label
    );

    ///
    /// \return код результата выполнения операции
    std::string get_status() {
        return status;
    };

    /// Идентификатор запроса платежа
    /// \return
    std::string get_request_id() {
        return request_id;
    };

    ///
    /// \return код ошибки при проведении платежа
    std::string get_error() {
        return error;
    };

    ///
    /// \return сумму к списанию со счета в валюте счета плательщика (столько заплатит пользователь вместе с комиссией).
    std::string get_contract_amount() {
        return contract_amount;
    };

    /// текущий баланс счета пользователя
    /// \return
    std::string get_balance() {
        return balance;
    };

};