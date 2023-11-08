#include <vector>
#include "cpr/cpr.h"
#include "dependencies/json.hpp"
#include <iostream>

/// \class Operation_history
/// \brief Класс, позволяющий просматривать историю операций

class Operation_history {
private:

    /// \class Operations
    /// \brief Класс, позволяющий хранить и работать с операциями
    class Operations {
        friend class Operation_history;

    private:
        /// Идентификатор операции
        /// \var operation_id
        std::string operation_id;

        /// Статус платежа (перевода)
        /// \var status
        std::string status;

        ///	Дата и время совершения операции
        /// \var datetime
        std::string datetime;

        /// Краткое описание операции
        /// \var title
        std::string title;

        /// Идентификатор шаблона, по которому совершен платеж. Присутствует только для платежей
        /// \var pattern_id
        std::string pattern_id;

        /// Направление движения средств
        /// \var direction
        std::string direction;

        /// Сумма операции
        /// \var amount
        std::string amount;

        /// Метка платежа
        /// \var label
        std::string label;

        /// Тип операции
        /// \var type
        std::string type;

        /// Сумма к получению. Присутствует для исходящих переводов другим пользователям
        /// \var amount_due
        std::string amount_due;

        /// Сумма комиссии. Присутствует для исходящих переводов другим пользователям
        /// \var fee
        std::string fee;

        /// Номер счета отправителя перевода. Присутствует для входящих переводов от других пользователей
        /// \var sender
        std::string sender;

        ///Статус платежа (перевода)
        /// \var recipient
        std::string recipient;

        /// Идентификатор получателя перевода. Присутствует для исходящих переводов другим пользователям
        /// \var recipient_type
        std::string recipient_type;

        Operations() = default;
    public:

        ///
        /// \return id операции
        const std::string &getOperationId() const;

        ///
        /// \return статус операции
        const std::string &getStatus() const;

        ///
        /// \return дата и время совершения операции.
        const std::string &getDatetime() const;

        ///
        /// \return краткое описание операции
        const std::string &getTitle() const;

        ///
        /// \return идентификатор шаблона, по которому совершен платеж.
        const std::string &getPatternId() const;

        ///
        /// \return направление движения средств
        const std::string &getDirection() const;

        ///
        /// \return сумму операции
        const std::string &getAmount() const;

        ///
        /// \return метку платежа
        const std::string &getLabel() const;

        ///
        /// \return тип операции
        const std::string &getType() const;

        ///
        /// \return сумму к получению
        const std::string &getAmountDue() const;

        ///
        /// \return сумму комиссии
        const std::string &getFee() const;

        ///
        /// \return номер счета отправителя перевода
        const std::string &getSender() const;

        ///
        /// \return идентификатор получателя перевода
        const std::string &getRecipient() const;

        ///
        /// \return тип идентификатора получателя перевода
        const std::string &getRecipientType() const;
    };

    ///Ключ для получения доступа к API
    /// \var api_key
    std::string api_key;

    ///Название метода для получения информации об истории операций
    /// \var method
    std::string method;

    /// Перечень типов операций, которые требуется отобразить
    /// \var type
    std::string type;

    /// Отбор платежей по значению метки
    /// \var label
    std::string label;

    /// Вывести операции от момента времени (операции, равные from, или более поздние)
    /// \var from
    std::string from;

    /// Вывести операции до момента времени (операции более ранние, чем till)
    /// \var till
    std::string till;

    /// Начала постраничного вывода (нумерация идет с 0)
    /// \var start_record
    int start_record;

    /// Количество запрашиваемых записей истории операций
    /// \var records
    int records;

    /// Порядковый номер первой записи на следующей странице истории операций
    /// \var next_record
    std::string next_record;

    /// Массив операций
    /// \var operations
    std::vector<Operations> operations;

    Operation_history() = default;

    nlohmann::json req();

public:
    /// Создает экземпляр класса Operation_history
    /// \param api_key API ключ для доступа
    /// \param method Название метода в URL
    /// \param type Перечень типов операций, которые требуется отобразить
    /// \param label Отбор платежей по значению метки
    /// \param from Вывести операции от момента времени (операции, равные from, или более поздние)
    /// \param till Вывести операции до момента времени (операции более ранние, чем till)
    /// \param start_record Порядковый номер первой записи на следующей странице истории операций
    /// \param records Количество запрашиваемых записей истории операций
    Operation_history(std::string api_key, std::string method, std::string type = "",
                      std::string label = "", std::string from = "", std::string till = "",
                      int start_record = 0, int records = 30);

    ///
    /// \return в виде строки Порядковый номер первой записи на следующей странице истории операций
    std::string getNextRecord();
    ///
    /// \return вектор операций
    const std::vector<Operations> getOperations() const;

};