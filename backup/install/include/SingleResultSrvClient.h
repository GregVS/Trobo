//
// Created by greg on 11/21/18.
//

#ifndef PROJECT_SERVICECLIENTWRAPPER_H
#define PROJECT_SERVICECLIENTWRAPPER_H

#include "ros/ros.h"
#include <optional>

template <typename SrvType>
class SingleResultSrvClient {
public:

    SingleResultSrvClient(ros::ServiceClient srvClient) {
        srvClient_ = std::make_unique<ros::ServiceClient>(srvClient);
    }

    template <typename ResultType>
    std::optional<const ResultType> callSrv(SrvType& service);

private:
    const std::unique_ptr<ros::ServiceClient> srvClient_;

};


#endif //PROJECT_SERVICECLIENTWRAPPER_H
