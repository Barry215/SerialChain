//
// Created by Frank on 18/6/1.
//

#ifndef SERIALCHAIN_RESULTMSG_H
#define SERIALCHAIN_RESULTMSG_H

#include <string>

using namespace std;

template<typename T>
class ResultMsg {

private:
    bool status;
    string msg;
    T data;

public:

    ResultMsg() = default;

    ResultMsg(bool status, const string &msg, T data);

    bool isStatus() const;

    void setStatus(bool status);

    const string &getMsg() const;

    void setMsg(const string &msg);

    T getData() const;

    void setData(T data);

    ResultMsg &operator=(const ResultMsg &resultMsg);

};

template<typename T>
ResultMsg<T>::ResultMsg(bool status, const string &msg, T data) : status(status), msg(msg), data(data) {}

template<typename T>
bool ResultMsg<T>::isStatus() const {
    return status;
}

template<typename T>
void ResultMsg<T>::setStatus(bool status) {
    ResultMsg::status = status;
}

template<typename T>
T ResultMsg<T>::getData() const {
    return data;
}

template<typename T>
void ResultMsg<T>::setData(T data) {
    ResultMsg::data = data;
}

template<typename T>
const string &ResultMsg<T>::getMsg() const {
    return msg;
}

template<typename T>
void ResultMsg<T>::setMsg(const string &msg) {
    ResultMsg::msg = msg;
}

template<typename T>
ResultMsg<T> &ResultMsg<T>::operator=(const ResultMsg &resultMsg) {
    status = resultMsg.isStatus();
    msg = resultMsg.getMsg();
    data = resultMsg.getData();
    return *this;
}

#endif //SERIALCHAIN_RESULTMSG_H
