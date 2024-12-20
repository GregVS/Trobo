// Generated by gencpp from file custom_msgs/ImagesAndBoxesSrv.msg
// DO NOT EDIT!


#ifndef CUSTOM_MSGS_MESSAGE_IMAGESANDBOXESSRV_H
#define CUSTOM_MSGS_MESSAGE_IMAGESANDBOXESSRV_H

#include <ros/service_traits.h>


#include <custom_msgs/ImagesAndBoxesSrvRequest.h>
#include <custom_msgs/ImagesAndBoxesSrvResponse.h>


namespace custom_msgs
{

struct ImagesAndBoxesSrv
{

typedef ImagesAndBoxesSrvRequest Request;
typedef ImagesAndBoxesSrvResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct ImagesAndBoxesSrv
} // namespace custom_msgs


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::custom_msgs::ImagesAndBoxesSrv > {
  static const char* value()
  {
    return "5d7f9b966106cb762e276fc9ad963134";
  }

  static const char* value(const ::custom_msgs::ImagesAndBoxesSrv&) { return value(); }
};

template<>
struct DataType< ::custom_msgs::ImagesAndBoxesSrv > {
  static const char* value()
  {
    return "custom_msgs/ImagesAndBoxesSrv";
  }

  static const char* value(const ::custom_msgs::ImagesAndBoxesSrv&) { return value(); }
};


// service_traits::MD5Sum< ::custom_msgs::ImagesAndBoxesSrvRequest> should match 
// service_traits::MD5Sum< ::custom_msgs::ImagesAndBoxesSrv > 
template<>
struct MD5Sum< ::custom_msgs::ImagesAndBoxesSrvRequest>
{
  static const char* value()
  {
    return MD5Sum< ::custom_msgs::ImagesAndBoxesSrv >::value();
  }
  static const char* value(const ::custom_msgs::ImagesAndBoxesSrvRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::custom_msgs::ImagesAndBoxesSrvRequest> should match 
// service_traits::DataType< ::custom_msgs::ImagesAndBoxesSrv > 
template<>
struct DataType< ::custom_msgs::ImagesAndBoxesSrvRequest>
{
  static const char* value()
  {
    return DataType< ::custom_msgs::ImagesAndBoxesSrv >::value();
  }
  static const char* value(const ::custom_msgs::ImagesAndBoxesSrvRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::custom_msgs::ImagesAndBoxesSrvResponse> should match 
// service_traits::MD5Sum< ::custom_msgs::ImagesAndBoxesSrv > 
template<>
struct MD5Sum< ::custom_msgs::ImagesAndBoxesSrvResponse>
{
  static const char* value()
  {
    return MD5Sum< ::custom_msgs::ImagesAndBoxesSrv >::value();
  }
  static const char* value(const ::custom_msgs::ImagesAndBoxesSrvResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::custom_msgs::ImagesAndBoxesSrvResponse> should match 
// service_traits::DataType< ::custom_msgs::ImagesAndBoxesSrv > 
template<>
struct DataType< ::custom_msgs::ImagesAndBoxesSrvResponse>
{
  static const char* value()
  {
    return DataType< ::custom_msgs::ImagesAndBoxesSrv >::value();
  }
  static const char* value(const ::custom_msgs::ImagesAndBoxesSrvResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // CUSTOM_MSGS_MESSAGE_IMAGESANDBOXESSRV_H
