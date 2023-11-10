#include "cpr/cpr.h"
#include "dependencies/json.hpp"


/// \class Account
/// \brief Класc для получение информации о состоянии счета пользователя.
///
class Account {
private:
    ///Ключ для получения доступа к API
    /// \var api_key
    std::string api_key;

    ///Название метода для получения информации о состоянии счета пользователя
    /// \var method
    std::string method;

    ///Номер счета пользователя.
    /// \var account
    std::string account;

    ///Баланс счета пользователя.
    /// \var balance
    std::string balance;

    ///Код валюты счета пользователя по стандарту ISO 4217
    /// \var currency
    std::string currency;

    ///Тип счета пользователя
    /// \var account_type
    std::string account_type;

    ///Статус пользователя
    /// \var account_status
    std::string account_status;

    //Параметры объекта balance_details
    std::string total;
    std::string available;
    std::string deposition_pending;
    std::string blocked;
    std::string debt;
    std::string hold;

    /// \class Card
    /// \brief Класс для хранения информации о привязанных банковских картах
    ///
    class Card {
        friend class Account;

    private:

        /// Маскированный номер карты
        /// \var pan_fragment
        std::string pan_fragment;

        /// Тип карты. Может отсутствовать, если неизвестен
        /// \var type
        std::string type;

        Card() = default;

    public:
        const std::string &getPanFragment() const;

        const std::string &getType() const;
    };

    Account() = default;

    nlohmann::json req();

    std::string bool_to_str(bool flag);

public:
    /// Создает экземпляр класса Account для получения информации об аккаунте
    /// \param api_key API ключ для доступа к операции
    /// \param method Название метода в URL
    Account(std::string api_key, std::string method);

    std::vector<Card> cards;

    ///
    /// \return номер счета пользователя
    std::string get_account() { return this->account; };

    ///
    /// \return баланс счета пользователя.
    std::string get_balance() { return this->balance; };

    ///
    /// \return код валюты счета пользователя
    std::string get_currency() { return this->currency; };

    ///
    /// \return тип счета пользователя
    std::string get_account_type() { return this->account_type; };

    ///
    /// \return статус пользователя
    std::string get_account_status() { return this->account_status; };

    ///
    /// \return общий баланс счета
    std::string get_total() { return this->total; };

    ///
    /// \return cумму доступную для расходных операций
    std::string get_available() { return this->available; };

    ///
    /// \return сумму стоящих в очереди пополнений
    std::string get_deposition_pending() { return this->deposition_pending; };

    ///
    /// \return сумму заблокированных средств по решению исполнительных органов
    std::string get_blocked() { return this->blocked; };

    ///
    /// \return сумму задолженности (отрицательного остатка на счете)
    std::string get_debt() { return this->debt; };

    ///
    /// \return сумму замороженных средств
    std::string get_hold() { return this->hold; };
};
