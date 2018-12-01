// Generated by gencpp from file custom_msgs/ActionSrvResponse.msg
// DO NOT EDIT!


#ifndef CUSTOM_MSGS_MESSAGE_ACTIONSRVRESPONSE_H
#define CUSTOM_MSGS_MESSAGE_ACTIONSRVRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <custom_msgs/Action.h>

namespace custom_msgs
{
template <class ContainerAllocator>
struct ActionSrvResponse_
{
  typedef ActionSrvResponse_<ContainerAllocator> Type;

  ActionSrvResponse_()
    : result()  {
    }
  ActionSrvResponse_(const ContainerAllocator& _alloc)
    : result(_alloc)  {
  (void)_alloc;
    }



   typedef  ::custom_msgs::Action_<ContainerAllocator>  _result_type;
  _result_type result;





  typedef boost::shared_ptr< ::custom_msgs::ActionSrvResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::custom_msgs::ActionSrvResponse_<ContainerAllocator> const> ConstPtr;

}; // struct ActionSrvResponse_

typedef ::custom_msgs::ActionSrvResponse_<std::allocator<void> > ActionSrvResponse;

typedef boost::shared_ptr< ::custom_msgs::ActionSrvResponse > ActionSrvResponsePtr;
typedef boost::shared_ptr< ::custom_msgs::ActionSrvResponse const> ActionSrvResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::custom_msgs::ActionSrvResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::custom_msgs::ActionSrvResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace custom_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/melodic/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/home/greg/trobo_cpp/src/common_msgs/geometry_msgs/msg'], 'sensor_msgs': ['/home/greg/trobo_cpp/src/common_msgs/sensor_msgs/msg'], 'custom_msgs': ['/home/greg/trobo_cpp/src/custom_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::custom_msgs::ActionSrvResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::custom_msgs::ActionSrvResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::custom_msgs::ActionSrvResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::custom_msgs::ActionSrvResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::custom_msgs::ActionSrvResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::custom_msgs::ActionSrvResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::custom_msgs::ActionSrvResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "e80c7b45afea0457eeb6cf7c0177651c";
  }

  static const char* value(const ::custom_msgs::ActionSrvResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xe80c7b45afea0457ULL;
  static const uint64_t static_value2 = 0xeeb6cf7c0177651cULL;
};

template<class ContainerAllocator>
struct DataType< ::custom_msgs::ActionSrvResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "custom_msgs/ActionSrvResponse";
  }

  static const char* value(const ::custom_msgs::ActionSrvResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::custom_msgs::ActionSrvResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "custom_msgs/Action result\n\
\n\
================================================================================\n\
MSG: custom_msgs/Action\n\
uint8 id\n\
float32[] params\n\
\n\
# The id codes are listed below\n\
# 0 - scoop\n\
# 1 - drive (left %, right %)\n\
# 2 - stop\n\
";
  }

  static const char* value(const ::custom_msgs::ActionSrvResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::custom_msgs::ActionSrvResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.result);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ActionSrvResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::custom_msgs::ActionSrvResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::custom_msgs::ActionSrvResponse_<ContainerAllocator>& v)
  {
    s << indent << "result: ";
    s << std::endl;
    Printer< ::custom_msgs::Action_<ContainerAllocator> >::stream(s, indent + "  ", v.result);
  }
};

} // namespace message_operations
} // namespace ros

#endif // CUSTOM_MSGS_MESSAGE_ACTIONSRVRESPONSE_H