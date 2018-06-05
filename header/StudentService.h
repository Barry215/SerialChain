//
// Created by Frank on 18/6/5.
//

#ifndef SERIALCHAIN_STUDENTSERVICE_H
#define SERIALCHAIN_STUDENTSERVICE_H

#include <string>
#include "ChainHandler.h"

class StudentService : public ChainHandler<string, string, string>{
public:
    virtual void execute(string &permanent, ResultMsg<string> &resultMsg, string &&parameter) override;

    virtual bool whetherExecute(string &permanent, ResultMsg<string> &resultMsg, string &&parameter) override;
};


#endif //SERIALCHAIN_STUDENTSERVICE_H
