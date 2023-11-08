/// \class Exception
/// \brief Дочерний класс от std::exception для вызова разных исключений
class Exception : public std::exception {
public:
    Exception(const std::string &msg) : msg(msg) {}

    const char *what() const noexcept {
        return msg.c_str();
    }

private:
    ///Сообщение исключения
    /// \var msg
    std::string msg;
};

/// \class InvalidToken
/// \brief Дочерний класс от Exception для вызова исключения. Сообщает о проблеме с токеном
class InvalidToken : public Exception {
public:
    InvalidToken() : Exception("Невалидный токен или нет соответствующих прав") {};
};

/// \class IllegalParamType
/// \brief Дочерний класс от Exception для вызова исключения. Сообщает о проблеме с параметром type
class IllegalParamType : public Exception {
public:
    IllegalParamType() : Exception("Неправильный параметр type") {};
};

/// \class IllegalParamStartRecord
/// \brief Дочерний класс от Exception для вызова исключения. Сообщает о проблеме с параметром start_record
class IllegalParamStartRecord : public Exception {
public:
    IllegalParamStartRecord() : Exception("Неправильный параметр start_record") {};
};

/// \class IllegalParamRecords
/// \brief Дочерний класс от Exception для вызова исключения. Сообщает о проблеме с параметром records
class IllegalParamRecords : public Exception {
public:
    IllegalParamRecords() : Exception("Неправильный параметр records") {};
};

/// \class IllegalParamLabel
/// \brief Дочерний класс от Exception для вызова исключения. Сообщает о проблеме с параметром label
class IllegalParamLabel : public Exception {
public:
    IllegalParamLabel() : Exception("Неправильный параметр label") {};
};

/// \class IllegalParamFromDate
/// \brief Дочерний класс от Exception для вызова исключения. Сообщает о проблеме с параметром from_date
class IllegalParamFromDate : public Exception {
public:
    IllegalParamFromDate() : Exception("Неправильный параметр from_date") {};
};

/// \class IllegalParamTillDate
/// \brief Дочерний класс от Exception для вызова исключения. Сообщает о проблеме с параметром till_date
class IllegalParamTillDate : public Exception {
public:
    IllegalParamTillDate() : Exception("Неправильный параметр till_date") {};
};

/// \class Technical
/// \brief Дочерний класс от Exception для вызова исключения. Сообщает о технический проблемах
class Technical : public Exception {
public:
    Technical() : Exception("Техническая проблема") {};
};