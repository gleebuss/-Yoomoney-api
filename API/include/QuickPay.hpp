#include "cpr/cpr.h"


/// \class QuickPay
/// \brief Класс, создать форму для платежа
class QuickPay {
private:
    QuickPay() = default;

    /// Ключ для получения доступа к API
    /// \var api_key
    std::string api_key;

    /// Номер кошелька ЮMoney, на который нужно зачислять деньги отправителей
    /// \var receiver
    std::string receiver;

    /// Сумма перевода (спишется с отправителя)
    /// \var sum
    std::string sum;

    cpr::Url req(std::string receiver,
                 std::string sum);


public:
    /// Создает экземпляр класса QuickPay для получения URL формы
    /// \param api_key API ключ для доступа к операции
    /// \param receiver Номер кошелька ЮMoney, на который нужно зачислять деньги отправителей
    /// \param sum Сумма перевода
    QuickPay(std::string api_key,
             std::string receiver,
             std::string sum);

    ///
    /// \return ссылку на URL
    cpr::Url get_url();
};