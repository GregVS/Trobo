// Generated by gencpp from file visualization_msgs/InteractiveMarkerInit.msg
// DO NOT EDIT!


#ifndef VISUALIZATION_MSGS_MESSAGE_INTERACTIVEMARKERINIT_H
#define VISUALIZATION_MSGS_MESSAGE_INTERACTIVEMARKERINIT_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <visualization_msgs/InteractiveMarker.h>

namespace visualization_msgs
{
template <class ContainerAllocator>
struct InteractiveMarkerInit_
{
  typedef InteractiveMarkerInit_<ContainerAllocator> Type;

  InteractiveMarkerInit_()
    : server_id()
    , seq_num(0)
    , markers()  {
    }
  InteractiveMarkerInit_(const ContainerAllocator& _alloc)
    : server_id(_alloc)
    , seq_num(0)
    , markers(_alloc)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _server_id_type;
  _server_id_type server_id;

   typedef uint64_t _seq_num_type;
  _seq_num_type seq_num;

   typedef std::vector< ::visualization_msgs::InteractiveMarker_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::visualization_msgs::InteractiveMarker_<ContainerAllocator> >::other >  _markers_type;
  _markers_type markers;





  typedef boost::shared_ptr< ::visualization_msgs::InteractiveMarkerInit_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::visualization_msgs::InteractiveMarkerInit_<ContainerAllocator> const> ConstPtr;

}; // struct InteractiveMarkerInit_

typedef ::visualization_msgs::InteractiveMarkerInit_<std::allocator<void> > InteractiveMarkerInit;

typedef boost::shared_ptr< ::visualization_msgs::InteractiveMarkerInit > InteractiveMarkerInitPtr;
typedef boost::shared_ptr< ::visualization_msgs::InteractiveMarkerInit const> InteractiveMarkerInitConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::visualization_msgs::InteractiveMarkerInit_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::visualization_msgs::InteractiveMarkerInit_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace visualization_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/melodic/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/home/greg/trobo_cpp/src/common_msgs/geometry_msgs/msg'], 'visualization_msgs': ['/home/greg/trobo_cpp/src/common_msgs/visualization_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::visualization_msgs::InteractiveMarkerInit_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::visualization_msgs::InteractiveMarkerInit_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::visualization_msgs::InteractiveMarkerInit_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::visualization_msgs::InteractiveMarkerInit_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::visualization_msgs::InteractiveMarkerInit_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::visualization_msgs::InteractiveMarkerInit_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::visualization_msgs::InteractiveMarkerInit_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d5f2c5045a72456d228676ab91048734";
  }

  static const char* value(const ::visualization_msgs::InteractiveMarkerInit_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd5f2c5045a72456dULL;
  static const uint64_t static_value2 = 0x228676ab91048734ULL;
};

template<class ContainerAllocator>
struct DataType< ::visualization_msgs::InteractiveMarkerInit_<ContainerAllocator> >
{
  static const char* value()
  {
    return "visualization_msgs/InteractiveMarkerInit";
  }

  static const char* value(const ::visualization_msgs::InteractiveMarkerInit_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::visualization_msgs::InteractiveMarkerInit_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# Identifying string. Must be unique in the topic namespace\n\
# that this server works on.\n\
string server_id\n\
\n\
# Sequence number.\n\
# The client will use this to detect if it has missed a subsequent\n\
# update.  Every update message will have the same sequence number as\n\
# an init message.  Clients will likely want to unsubscribe from the\n\
# init topic after a successful initialization to avoid receiving\n\
# duplicate data.\n\
uint64 seq_num\n\
\n\
# All markers.\n\
InteractiveMarker[] markers\n\
\n\
================================================================================\n\
MSG: visualization_msgs/InteractiveMarker\n\
# Time/frame info.\n\
# If header.time is set to 0, the marker will be retransformed into\n\
# its frame on each timestep. You will receive the pose feedback\n\
# in the same frame.\n\
# Otherwise, you might receive feedback in a different frame.\n\
# For rviz, this will be the current 'fixed frame' set by the user.\n\
Header header\n\
\n\
# Initial pose. Also, defines the pivot point for rotations.\n\
geometry_msgs/Pose pose\n\
\n\
# Identifying string. Must be globally unique in\n\
# the topic that this message is sent through.\n\
string name\n\
\n\
# Short description (< 40 characters).\n\
string description\n\
\n\
# Scale to be used for default controls (default=1).\n\
float32 scale\n\
\n\
# All menu and submenu entries associated with this marker.\n\
MenuEntry[] menu_entries\n\
\n\
# List of controls displayed for this marker.\n\
InteractiveMarkerControl[] controls\n\
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
MSG: geometry_msgs/Pose\n\
# A representation of pose in free space, composed of position and orientation. \n\
Point position\n\
Quaternion orientation\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Point\n\
# This contains the position of a point in free space\n\
float64 x\n\
float64 y\n\
float64 z\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Quaternion\n\
# This represents an orientation in free space in quaternion form.\n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
float64 w\n\
\n\
================================================================================\n\
MSG: visualization_msgs/MenuEntry\n\
# MenuEntry message.\n\
\n\
# Each InteractiveMarker message has an array of MenuEntry messages.\n\
# A collection of MenuEntries together describe a\n\
# menu/submenu/subsubmenu/etc tree, though they are stored in a flat\n\
# array.  The tree structure is represented by giving each menu entry\n\
# an ID number and a \"parent_id\" field.  Top-level entries are the\n\
# ones with parent_id = 0.  Menu entries are ordered within their\n\
# level the same way they are ordered in the containing array.  Parent\n\
# entries must appear before their children.\n\
\n\
# Example:\n\
# - id = 3\n\
#   parent_id = 0\n\
#   title = \"fun\"\n\
# - id = 2\n\
#   parent_id = 0\n\
#   title = \"robot\"\n\
# - id = 4\n\
#   parent_id = 2\n\
#   title = \"pr2\"\n\
# - id = 5\n\
#   parent_id = 2\n\
#   title = \"turtle\"\n\
#\n\
# Gives a menu tree like this:\n\
#  - fun\n\
#  - robot\n\
#    - pr2\n\
#    - turtle\n\
\n\
# ID is a number for each menu entry.  Must be unique within the\n\
# control, and should never be 0.\n\
uint32 id\n\
\n\
# ID of the parent of this menu entry, if it is a submenu.  If this\n\
# menu entry is a top-level entry, set parent_id to 0.\n\
uint32 parent_id\n\
\n\
# menu / entry title\n\
string title\n\
\n\
# Arguments to command indicated by command_type (below)\n\
string command\n\
\n\
# Command_type stores the type of response desired when this menu\n\
# entry is clicked.\n\
# FEEDBACK: send an InteractiveMarkerFeedback message with menu_entry_id set to this entry's id.\n\
# ROSRUN: execute \"rosrun\" with arguments given in the command field (above).\n\
# ROSLAUNCH: execute \"roslaunch\" with arguments given in the command field (above).\n\
uint8 FEEDBACK=0\n\
uint8 ROSRUN=1\n\
uint8 ROSLAUNCH=2\n\
uint8 command_type\n\
\n\
================================================================================\n\
MSG: visualization_msgs/InteractiveMarkerControl\n\
# Represents a control that is to be displayed together with an interactive marker\n\
\n\
# Identifying string for this control.\n\
# You need to assign a unique value to this to receive feedback from the GUI\n\
# on what actions the user performs on this control (e.g. a button click).\n\
string name\n\
\n\
\n\
# Defines the local coordinate frame (relative to the pose of the parent\n\
# interactive marker) in which is being rotated and translated.\n\
# Default: Identity\n\
geometry_msgs/Quaternion orientation\n\
\n\
\n\
# Orientation mode: controls how orientation changes.\n\
# INHERIT: Follow orientation of interactive marker\n\
# FIXED: Keep orientation fixed at initial state\n\
# VIEW_FACING: Align y-z plane with screen (x: forward, y:left, z:up).\n\
uint8 INHERIT = 0 \n\
uint8 FIXED = 1\n\
uint8 VIEW_FACING = 2\n\
\n\
uint8 orientation_mode\n\
\n\
# Interaction mode for this control\n\
# \n\
# NONE: This control is only meant for visualization; no context menu.\n\
# MENU: Like NONE, but right-click menu is active.\n\
# BUTTON: Element can be left-clicked.\n\
# MOVE_AXIS: Translate along local x-axis.\n\
# MOVE_PLANE: Translate in local y-z plane.\n\
# ROTATE_AXIS: Rotate around local x-axis.\n\
# MOVE_ROTATE: Combines MOVE_PLANE and ROTATE_AXIS.\n\
uint8 NONE = 0 \n\
uint8 MENU = 1\n\
uint8 BUTTON = 2\n\
uint8 MOVE_AXIS = 3 \n\
uint8 MOVE_PLANE = 4\n\
uint8 ROTATE_AXIS = 5\n\
uint8 MOVE_ROTATE = 6\n\
# \"3D\" interaction modes work with the mouse+SHIFT+CTRL or with 3D cursors.\n\
# MOVE_3D: Translate freely in 3D space.\n\
# ROTATE_3D: Rotate freely in 3D space about the origin of parent frame.\n\
# MOVE_ROTATE_3D: Full 6-DOF freedom of translation and rotation about the cursor origin.\n\
uint8 MOVE_3D = 7\n\
uint8 ROTATE_3D = 8\n\
uint8 MOVE_ROTATE_3D = 9\n\
\n\
uint8 interaction_mode\n\
\n\
\n\
# If true, the contained markers will also be visible\n\
# when the gui is not in interactive mode.\n\
bool always_visible\n\
\n\
\n\
# Markers to be displayed as custom visual representation.\n\
# Leave this empty to use the default control handles.\n\
#\n\
# Note: \n\
# - The markers can be defined in an arbitrary coordinate frame,\n\
#   but will be transformed into the local frame of the interactive marker.\n\
# - If the header of a marker is empty, its pose will be interpreted as \n\
#   relative to the pose of the parent interactive marker.\n\
Marker[] markers\n\
\n\
\n\
# In VIEW_FACING mode, set this to true if you don't want the markers\n\
# to be aligned with the camera view point. The markers will show up\n\
# as in INHERIT mode.\n\
bool independent_marker_orientation\n\
\n\
\n\
# Short description (< 40 characters) of what this control does,\n\
# e.g. \"Move the robot\". \n\
# Default: A generic description based on the interaction mode\n\
string description\n\
\n\
================================================================================\n\
MSG: visualization_msgs/Marker\n\
# See http://www.ros.org/wiki/rviz/DisplayTypes/Marker and http://www.ros.org/wiki/rviz/Tutorials/Markers%3A%20Basic%20Shapes for more information on using this message with rviz\n\
\n\
uint8 ARROW=0\n\
uint8 CUBE=1\n\
uint8 SPHERE=2\n\
uint8 CYLINDER=3\n\
uint8 LINE_STRIP=4\n\
uint8 LINE_LIST=5\n\
uint8 CUBE_LIST=6\n\
uint8 SPHERE_LIST=7\n\
uint8 POINTS=8\n\
uint8 TEXT_VIEW_FACING=9\n\
uint8 MESH_RESOURCE=10\n\
uint8 TRIANGLE_LIST=11\n\
\n\
uint8 ADD=0\n\
uint8 MODIFY=0\n\
uint8 DELETE=2\n\
uint8 DELETEALL=3\n\
\n\
Header header                        # header for time/frame information\n\
string ns                            # Namespace to place this object in... used in conjunction with id to create a unique name for the object\n\
int32 id 		                         # object ID useful in conjunction with the namespace for manipulating and deleting the object later\n\
int32 type 		                       # Type of object\n\
int32 action 	                       # 0 add/modify an object, 1 (deprecated), 2 deletes an object, 3 deletes all objects\n\
geometry_msgs/Pose pose                 # Pose of the object\n\
geometry_msgs/Vector3 scale             # Scale of the object 1,1,1 means default (usually 1 meter square)\n\
std_msgs/ColorRGBA color             # Color [0.0-1.0]\n\
duration lifetime                    # How long the object should last before being automatically deleted.  0 means forever\n\
bool frame_locked                    # If this marker should be frame-locked, i.e. retransformed into its frame every timestep\n\
\n\
#Only used if the type specified has some use for them (eg. POINTS, LINE_STRIP, ...)\n\
geometry_msgs/Point[] points\n\
#Only used if the type specified has some use for them (eg. POINTS, LINE_STRIP, ...)\n\
#number of colors must either be 0 or equal to the number of points\n\
#NOTE: alpha is not yet used\n\
std_msgs/ColorRGBA[] colors\n\
\n\
# NOTE: only used for text markers\n\
string text\n\
\n\
# NOTE: only used for MESH_RESOURCE markers\n\
string mesh_resource\n\
bool mesh_use_embedded_materials\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Vector3\n\
# This represents a vector in free space. \n\
# It is only meant to represent a direction. Therefore, it does not\n\
# make sense to apply a translation to it (e.g., when applying a \n\
# generic rigid transformation to a Vector3, tf2 will only apply the\n\
# rotation). If you want your data to be translatable too, use the\n\
# geometry_msgs/Point message instead.\n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
================================================================================\n\
MSG: std_msgs/ColorRGBA\n\
float32 r\n\
float32 g\n\
float32 b\n\
float32 a\n\
";
  }

  static const char* value(const ::visualization_msgs::InteractiveMarkerInit_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::visualization_msgs::InteractiveMarkerInit_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.server_id);
      stream.next(m.seq_num);
      stream.next(m.markers);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct InteractiveMarkerInit_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::visualization_msgs::InteractiveMarkerInit_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::visualization_msgs::InteractiveMarkerInit_<ContainerAllocator>& v)
  {
    s << indent << "server_id: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.server_id);
    s << indent << "seq_num: ";
    Printer<uint64_t>::stream(s, indent + "  ", v.seq_num);
    s << indent << "markers[]" << std::endl;
    for (size_t i = 0; i < v.markers.size(); ++i)
    {
      s << indent << "  markers[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::visualization_msgs::InteractiveMarker_<ContainerAllocator> >::stream(s, indent + "    ", v.markers[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // VISUALIZATION_MSGS_MESSAGE_INTERACTIVEMARKERINIT_H