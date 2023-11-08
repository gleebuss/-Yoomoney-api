#include "Authorize.hpp"

/// Позволяет получить Api ключ для дальнейшей работы
/// \param client_id - Идентификатор приложения, полученный при регистрации,
/// \param redirect_uri - URI, на который OAuth-сервер передает результат авторизации,
/// \param client_secret - Секретное слово для проверки подлинности приложения.
Authorize::Authorize(std::string client_id, std::string redirect_uri, std::string client_secret) {
    //первый этап получения токена
    auto first_data = nlohmann::json{{"client_id",     client_id},
                                     {"response_type", "code"},
                                     {"redirect_uri",  redirect_uri},
                                     {"scope",         "account-info operation-history operation-details incoming-transfers payment-p2p payment-shop"}};

    cpr::Response first_req = cpr::Post(cpr::Url{"https://yoomoney.ru/oauth/authorize"},
                                        cpr::Header{{"Content-Type", "application/json"}},
                                        cpr::Body{nlohmann::to_string(first_data)});

    std::cout << first_req.url << "\n" << "Введите ссылку:" << "\n";

    std::string tmp;
    std::cin >> tmp;
    std::cout << "\n";

    auto index = tmp.rfind("=");
    std::string code = tmp.substr(index + 1, tmp.length());

    //второй заключительный этап получения токена
    auto second_data = nlohmann::json{{"client_id",     client_id},
                                      {"grant_type",    "authorization_code"},
                                      {"redirect_uri",  redirect_uri},
                                      {"code",          code},
                                      {"client_secret", client_secret}};

    cpr::Response second_req = cpr::Post(cpr::Url{"https://yoomoney.ru/oauth/token"},
                                         cpr::Header{{"Content-Type", "application/json"}},
                                         cpr::Body{nlohmann::to_string(second_data)});

    std::cout << "Ваш Api ключ" << "\n" << second_req.text << "\n";

}