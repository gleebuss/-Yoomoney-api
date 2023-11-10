#include <string>
#include "dependencies/json.hpp"
#include <iostream>
#include <cpr/cpr.h>

/// \class Authorize
/// \brief Класс, отвечающий за получение токена
class Authorize
{
private:
    Authorize() = default;
public:
    /// Создает экземпляр класcа Authorize для получения токена
    /// \param client_id Идентификатор приложения, полученный при регистрации
    /// \param redirect_uri URI, на который сервер OAuth передает результат авторизации
    /// \param client_secret Секретное слово для проверки подлинности приложения
    Authorize(std::string client_id, std::string redirect_uri, std::string client_secret);
};