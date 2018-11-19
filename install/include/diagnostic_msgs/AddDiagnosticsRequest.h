// Generated by gencpp from file diagnostic_msgs/AddDiagnosticsRequest.msg
// DO NOT EDIT!


#ifndef DIAGNOSTIC_MSGS_MESSAGE_ADDDIAGNOSTICSREQUEST_H
#define DIAGNOSTIC_MSGS_MESSAGE_ADDDIAGNOSTICSREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace diagnostic_msgs
{
template <class ContainerAllocator>
struct AddDiagnosticsRequest_
{
  typedef AddDiagnosticsRequest_<ContainerAllocator> Type;

  AddDiagnosticsRequest_()
    : load_namespace()  {
    }
  AddDiagnosticsRequest_(const ContainerAllocator& _alloc)
    : load_namespace(_alloc)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _load_namespace_type;
  _load_namespace_type load_namespace;





  typedef boost::shared_ptr< ::diagnostic_msgs::AddDiagnosticsRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::diagnostic_msgs::AddDiagnosticsRequest_<ContainerAllocator> const> ConstPtr;

}; // struct AddDiagnosticsRequest_

typedef ::diagnostic_msgs::AddDiagnosticsRequest_<std::allocator<void> > AddDiagnosticsRequest;

typedef boost::shared_ptr< ::diagnostic_msgs::AddDiagnosticsRequest > AddDiagnosticsRequestPtr;
typedef boost::shared_ptr< ::diagnostic_msgs::AddDiagnosticsRequest const> AddDiagnosticsRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::diagnostic_msgs::AddDiagnosticsRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::diagnostic_msgs::AddDiagnosticsRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace diagnostic_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/melodic/share/std_msgs/cmake/../msg'], 'diagnostic_msgs': ['/home/greg/trobo_cpp/src/common_msgs/diagnostic_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::diagnostic_msgs::AddDiagnosticsRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::diagnostic_msgs::AddDiagnosticsRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::diagnostic_msgs::AddDiagnosticsRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::diagnostic_msgs::AddDiagnosticsRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::diagnostic_msgs::AddDiagnosticsRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::diagnostic_msgs::AddDiagnosticsRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::diagnostic_msgs::AddDiagnosticsRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "c26cf6e164288fbc6050d74f838bcdf0";
  }

  static const char* value(const ::diagnostic_msgs::AddDiagnosticsRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xc26cf6e164288fbcULL;
  static const uint64_t static_value2 = 0x6050d74f838bcdf0ULL;
};

template<class ContainerAllocator>
struct DataType< ::diagnostic_msgs::AddDiagnosticsRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "diagnostic_msgs/AddDiagnosticsRequest";
  }

  static const char* value(const ::diagnostic_msgs::AddDiagnosticsRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::diagnostic_msgs::AddDiagnosticsRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n\
\n\
\n\
\n\
\n\
\n\
\n\
\n\
\n\
\n\
\n\
\n\
\n\
\n\
\n\
\n\
string load_namespace\n\
";
  }

  static const char* value(const ::diagnostic_msgs::AddDiagnosticsRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::diagnostic_msgs::AddDiagnosticsRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.load_namespace);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct AddDiagnosticsRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::diagnostic_msgs::AddDiagnosticsRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::diagnostic_msgs::AddDiagnosticsRequest_<ContainerAllocator>& v)
  {
    s << indent << "load_namespace: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.load_namespace);
  }
};

} // namespace message_operations
} // namespace ros

#endif // DIAGNOSTIC_MSGS_MESSAGE_ADDDIAGNOSTICSREQUEST_H
