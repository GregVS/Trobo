// Generated by gencpp from file custom_msgs/ImagesAndBoxes.msg
// DO NOT EDIT!


#ifndef CUSTOM_MSGS_MESSAGE_IMAGESANDBOXES_H
#define CUSTOM_MSGS_MESSAGE_IMAGESANDBOXES_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <sensor_msgs/Image.h>
#include <sensor_msgs/Image.h>
#include <custom_msgs/Box.h>
#include <custom_msgs/Box.h>

namespace custom_msgs
{
template <class ContainerAllocator>
struct ImagesAndBoxes_
{
  typedef ImagesAndBoxes_<ContainerAllocator> Type;

  ImagesAndBoxes_()
    : bot_img()
    , top_img()
    , bot_img_boxes()
    , top_img_boxes()  {
    }
  ImagesAndBoxes_(const ContainerAllocator& _alloc)
    : bot_img(_alloc)
    , top_img(_alloc)
    , bot_img_boxes(_alloc)
    , top_img_boxes(_alloc)  {
  (void)_alloc;
    }



   typedef  ::sensor_msgs::Image_<ContainerAllocator>  _bot_img_type;
  _bot_img_type bot_img;

   typedef  ::sensor_msgs::Image_<ContainerAllocator>  _top_img_type;
  _top_img_type top_img;

   typedef std::vector< ::custom_msgs::Box_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::custom_msgs::Box_<ContainerAllocator> >::other >  _bot_img_boxes_type;
  _bot_img_boxes_type bot_img_boxes;

   typedef std::vector< ::custom_msgs::Box_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::custom_msgs::Box_<ContainerAllocator> >::other >  _top_img_boxes_type;
  _top_img_boxes_type top_img_boxes;





  typedef boost::shared_ptr< ::custom_msgs::ImagesAndBoxes_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::custom_msgs::ImagesAndBoxes_<ContainerAllocator> const> ConstPtr;

}; // struct ImagesAndBoxes_

typedef ::custom_msgs::ImagesAndBoxes_<std::allocator<void> > ImagesAndBoxes;

typedef boost::shared_ptr< ::custom_msgs::ImagesAndBoxes > ImagesAndBoxesPtr;
typedef boost::shared_ptr< ::custom_msgs::ImagesAndBoxes const> ImagesAndBoxesConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::custom_msgs::ImagesAndBoxes_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::custom_msgs::ImagesAndBoxes_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::custom_msgs::ImagesAndBoxes_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::custom_msgs::ImagesAndBoxes_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::custom_msgs::ImagesAndBoxes_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::custom_msgs::ImagesAndBoxes_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::custom_msgs::ImagesAndBoxes_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::custom_msgs::ImagesAndBoxes_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::custom_msgs::ImagesAndBoxes_<ContainerAllocator> >
{
  static const char* value()
  {
    return "154afe0ce1a929ba4bd762dc5f49fc14";
  }

  static const char* value(const ::custom_msgs::ImagesAndBoxes_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x154afe0ce1a929baULL;
  static const uint64_t static_value2 = 0x4bd762dc5f49fc14ULL;
};

template<class ContainerAllocator>
struct DataType< ::custom_msgs::ImagesAndBoxes_<ContainerAllocator> >
{
  static const char* value()
  {
    return "custom_msgs/ImagesAndBoxes";
  }

  static const char* value(const ::custom_msgs::ImagesAndBoxes_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::custom_msgs::ImagesAndBoxes_<ContainerAllocator> >
{
  static const char* value()
  {
    return "sensor_msgs/Image bot_img\n\
sensor_msgs/Image top_img\n\
Box[] bot_img_boxes\n\
Box[] top_img_boxes\n\
================================================================================\n\
MSG: sensor_msgs/Image\n\
# This message contains an uncompressed image\n\
# (0, 0) is at top-left corner of image\n\
#\n\
\n\
Header header        # Header timestamp should be acquisition time of image\n\
                     # Header frame_id should be optical frame of camera\n\
                     # origin of frame should be optical center of camera\n\
                     # +x should point to the right in the image\n\
                     # +y should point down in the image\n\
                     # +z should point into to plane of the image\n\
                     # If the frame_id here and the frame_id of the CameraInfo\n\
                     # message associated with the image conflict\n\
                     # the behavior is undefined\n\
\n\
uint32 height         # image height, that is, number of rows\n\
uint32 width          # image width, that is, number of columns\n\
\n\
# The legal values for encoding are in file src/image_encodings.cpp\n\
# If you want to standardize a new string format, join\n\
# ros-users@lists.sourceforge.net and send an email proposing a new encoding.\n\
\n\
string encoding       # Encoding of pixels -- channel meaning, ordering, size\n\
                      # taken from the list of strings in include/sensor_msgs/image_encodings.h\n\
\n\
uint8 is_bigendian    # is this data bigendian?\n\
uint32 step           # Full row length in bytes\n\
uint8[] data          # actual matrix data, size is (step * rows)\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
================================================================================\n\
MSG: custom_msgs/Box\n\
float32 left\n\
float32 top\n\
float32 right\n\
float32 bottom\n\
\n\
string id\n\
# the id should not be changed from 0 except for by the object prediction algorithm\n\
";
  }

  static const char* value(const ::custom_msgs::ImagesAndBoxes_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::custom_msgs::ImagesAndBoxes_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.bot_img);
      stream.next(m.top_img);
      stream.next(m.bot_img_boxes);
      stream.next(m.top_img_boxes);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ImagesAndBoxes_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::custom_msgs::ImagesAndBoxes_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::custom_msgs::ImagesAndBoxes_<ContainerAllocator>& v)
  {
    s << indent << "bot_img: ";
    s << std::endl;
    Printer< ::sensor_msgs::Image_<ContainerAllocator> >::stream(s, indent + "  ", v.bot_img);
    s << indent << "top_img: ";
    s << std::endl;
    Printer< ::sensor_msgs::Image_<ContainerAllocator> >::stream(s, indent + "  ", v.top_img);
    s << indent << "bot_img_boxes[]" << std::endl;
    for (size_t i = 0; i < v.bot_img_boxes.size(); ++i)
    {
      s << indent << "  bot_img_boxes[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::custom_msgs::Box_<ContainerAllocator> >::stream(s, indent + "    ", v.bot_img_boxes[i]);
    }
    s << indent << "top_img_boxes[]" << std::endl;
    for (size_t i = 0; i < v.top_img_boxes.size(); ++i)
    {
      s << indent << "  top_img_boxes[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::custom_msgs::Box_<ContainerAllocator> >::stream(s, indent + "    ", v.top_img_boxes[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // CUSTOM_MSGS_MESSAGE_IMAGESANDBOXES_H
