#include "Account.hpp"
#include "QuickPay.hpp"
#include "Operation_history.hpp"
#include "Request_payment.hpp"
#include "Process_payment.hpp"


/// \class Api
/// \brief Класс, отвечающий за доступ ко всему API Yoomoney.
///
class Api {
private:
    ///Ключ для получения доступа к API
    /// \var api_key
    std::string api_key;

    ///Базовый url API
    /// \var base_url
    const std::string base_url = "https://yoomoney.ru/api/";

    Api() = default;

public:
    /// Создает объект API для дальнейшей работы
    /// \param api_key API ключ для доступа
    Api(const std::string api_key) {
        this->api_key = api_key;
    };

    /// Экземпляр класса Account нужен для получения информации об аккаунте
    /// \return экзепляр класса Account
    Account account_info() {
        std::string method = "account-info";
        return Account(this->api_key, method);
    }

    /// Экземпляр класса Operation_history нужен для получения истории операции
    /// \param type Перечень типов операций, которые требуется отобразить
    /// \param label Отбор платежей по значению метки
    /// \param from Вывести операции от момента времени (операции, равные from, или более поздние)
    /// \param till Вывести операции до момента времени (операции более ранние, чем till)
    /// \param start_record Если параметр присутствует, то будут отображены операции, начиная с номера start_record, то есть с 0
    /// \param records Количество запрашиваемых записей истории операций
    /// \return экзепляр класса Operation_history
    Operation_history operation_history(std::string type = "",
                                        std::string label = "", std::string from = "", std::string till = "",
                                        int start_record = 0, int records = 30) {
        std::string method = "operation-history";
        return Operation_history(this->api_key, method, type, label, from, till, start_record, records);
    };

    /// Экземпляр класса Request_payment нужен для создания платежа
    /// \param to Идентификатор получателя перевода
    /// \param amount Сумма к оплате (столько заплатит отправитель)
    /// \param comment Комментарий к переводу, отображается в истории отправителя
    /// \param message Комментарий к переводу, отображается получателю
    /// \param label Метка платежа. Необязательный параметр
    /// \return экзепляр класса Request_payment
    Request_payment request_payment(std::string to,
                                    std::string amount,
                                    std::string comment = "",
                                    std::string message = "",
                                    std::string label = "") {
        std::string method = "request-payment";
        return Request_payment(this->api_key, method,
                               to,
                               amount,
                               comment,
                               message,
                               label);
    };

    /// Экземпляр класса Process_payment нужен для подтверждения платежа
    /// \param request_id Идентификатор запроса, полученный из ответа метода request-payment.
    /// \return экзепляр класса Process_payment
    Process_payment process_payment(std::string request_id) {
        std::string method = "process-payment";
        return Process_payment(this->api_key, method, request_id);
    }

    /// Экземпляр класса QuickPay нужен для создания формы
    /// \param receiver Номер кошелька ЮMoney, на который нужно зачислять деньги отправителей
    /// \param sum Сумма перевода (спишется с отправителя)
    /// \return экзепляр класса QuickPay
    QuickPay form(std::string receiver,
                  std::string sum) {
        return QuickPay(this->api_key, receiver, sum);
    };
};