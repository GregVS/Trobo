# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from custom_msgs/ImagesAndBoxes.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import custom_msgs.msg
import std_msgs.msg
import sensor_msgs.msg

class ImagesAndBoxes(genpy.Message):
  _md5sum = "154afe0ce1a929ba4bd762dc5f49fc14"
  _type = "custom_msgs/ImagesAndBoxes"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """sensor_msgs/Image bot_img
sensor_msgs/Image top_img
Box[] bot_img_boxes
Box[] top_img_boxes
================================================================================
MSG: sensor_msgs/Image
# This message contains an uncompressed image
# (0, 0) is at top-left corner of image
#

Header header        # Header timestamp should be acquisition time of image
                     # Header frame_id should be optical frame of camera
                     # origin of frame should be optical center of camera
                     # +x should point to the right in the image
                     # +y should point down in the image
                     # +z should point into to plane of the image
                     # If the frame_id here and the frame_id of the CameraInfo
                     # message associated with the image conflict
                     # the behavior is undefined

uint32 height         # image height, that is, number of rows
uint32 width          # image width, that is, number of columns

# The legal values for encoding are in file src/image_encodings.cpp
# If you want to standardize a new string format, join
# ros-users@lists.sourceforge.net and send an email proposing a new encoding.

string encoding       # Encoding of pixels -- channel meaning, ordering, size
                      # taken from the list of strings in include/sensor_msgs/image_encodings.h

uint8 is_bigendian    # is this data bigendian?
uint32 step           # Full row length in bytes
uint8[] data          # actual matrix data, size is (step * rows)

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
# 0: no frame
# 1: global frame
string frame_id

================================================================================
MSG: custom_msgs/Box
float32 left
float32 top
float32 right
float32 bottom

string id
# the id should not be changed from 0 except for by the object prediction algorithm"""
  __slots__ = ['bot_img','top_img','bot_img_boxes','top_img_boxes']
  _slot_types = ['sensor_msgs/Image','sensor_msgs/Image','custom_msgs/Box[]','custom_msgs/Box[]']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       bot_img,top_img,bot_img_boxes,top_img_boxes

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(ImagesAndBoxes, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.bot_img is None:
        self.bot_img = sensor_msgs.msg.Image()
      if self.top_img is None:
        self.top_img = sensor_msgs.msg.Image()
      if self.bot_img_boxes is None:
        self.bot_img_boxes = []
      if self.top_img_boxes is None:
        self.top_img_boxes = []
    else:
      self.bot_img = sensor_msgs.msg.Image()
      self.top_img = sensor_msgs.msg.Image()
      self.bot_img_boxes = []
      self.top_img_boxes = []

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_get_struct_3I().pack(_x.bot_img.header.seq, _x.bot_img.header.stamp.secs, _x.bot_img.header.stamp.nsecs))
      _x = self.bot_img.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_get_struct_2I().pack(_x.bot_img.height, _x.bot_img.width))
      _x = self.bot_img.encoding
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_get_struct_BI().pack(_x.bot_img.is_bigendian, _x.bot_img.step))
      _x = self.bot_img.data
      length = len(_x)
      # - if encoded as a list instead, serialize as bytes instead of string
      if type(_x) in [list, tuple]:
        buff.write(struct.pack('<I%sB'%length, length, *_x))
      else:
        buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_get_struct_3I().pack(_x.top_img.header.seq, _x.top_img.header.stamp.secs, _x.top_img.header.stamp.nsecs))
      _x = self.top_img.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_get_struct_2I().pack(_x.top_img.height, _x.top_img.width))
      _x = self.top_img.encoding
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_get_struct_BI().pack(_x.top_img.is_bigendian, _x.top_img.step))
      _x = self.top_img.data
      length = len(_x)
      # - if encoded as a list instead, serialize as bytes instead of string
      if type(_x) in [list, tuple]:
        buff.write(struct.pack('<I%sB'%length, length, *_x))
      else:
        buff.write(struct.pack('<I%ss'%length, length, _x))
      length = len(self.bot_img_boxes)
      buff.write(_struct_I.pack(length))
      for val1 in self.bot_img_boxes:
        _x = val1
        buff.write(_get_struct_4f().pack(_x.left, _x.top, _x.right, _x.bottom))
        _x = val1.id
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.pack('<I%ss'%length, length, _x))
      length = len(self.top_img_boxes)
      buff.write(_struct_I.pack(length))
      for val1 in self.top_img_boxes:
        _x = val1
        buff.write(_get_struct_4f().pack(_x.left, _x.top, _x.right, _x.bottom))
        _x = val1.id
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.pack('<I%ss'%length, length, _x))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      if self.bot_img is None:
        self.bot_img = sensor_msgs.msg.Image()
      if self.top_img is None:
        self.top_img = sensor_msgs.msg.Image()
      if self.bot_img_boxes is None:
        self.bot_img_boxes = None
      if self.top_img_boxes is None:
        self.top_img_boxes = None
      end = 0
      _x = self
      start = end
      end += 12
      (_x.bot_img.header.seq, _x.bot_img.header.stamp.secs, _x.bot_img.header.stamp.nsecs,) = _get_struct_3I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.bot_img.header.frame_id = str[start:end].decode('utf-8')
      else:
        self.bot_img.header.frame_id = str[start:end]
      _x = self
      start = end
      end += 8
      (_x.bot_img.height, _x.bot_img.width,) = _get_struct_2I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.bot_img.encoding = str[start:end].decode('utf-8')
      else:
        self.bot_img.encoding = str[start:end]
      _x = self
      start = end
      end += 5
      (_x.bot_img.is_bigendian, _x.bot_img.step,) = _get_struct_BI().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      self.bot_img.data = str[start:end]
      _x = self
      start = end
      end += 12
      (_x.top_img.header.seq, _x.top_img.header.stamp.secs, _x.top_img.header.stamp.nsecs,) = _get_struct_3I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.top_img.header.frame_id = str[start:end].decode('utf-8')
      else:
        self.top_img.header.frame_id = str[start:end]
      _x = self
      start = end
      end += 8
      (_x.top_img.height, _x.top_img.width,) = _get_struct_2I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.top_img.encoding = str[start:end].decode('utf-8')
      else:
        self.top_img.encoding = str[start:end]
      _x = self
      start = end
      end += 5
      (_x.top_img.is_bigendian, _x.top_img.step,) = _get_struct_BI().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      self.top_img.data = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.bot_img_boxes = []
      for i in range(0, length):
        val1 = custom_msgs.msg.Box()
        _x = val1
        start = end
        end += 16
        (_x.left, _x.top, _x.right, _x.bottom,) = _get_struct_4f().unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          val1.id = str[start:end].decode('utf-8')
        else:
          val1.id = str[start:end]
        self.bot_img_boxes.append(val1)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.top_img_boxes = []
      for i in range(0, length):
        val1 = custom_msgs.msg.Box()
        _x = val1
        start = end
        end += 16
        (_x.left, _x.top, _x.right, _x.bottom,) = _get_struct_4f().unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          val1.id = str[start:end].decode('utf-8')
        else:
          val1.id = str[start:end]
        self.top_img_boxes.append(val1)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_get_struct_3I().pack(_x.bot_img.header.seq, _x.bot_img.header.stamp.secs, _x.bot_img.header.stamp.nsecs))
      _x = self.bot_img.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_get_struct_2I().pack(_x.bot_img.height, _x.bot_img.width))
      _x = self.bot_img.encoding
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_get_struct_BI().pack(_x.bot_img.is_bigendian, _x.bot_img.step))
      _x = self.bot_img.data
      length = len(_x)
      # - if encoded as a list instead, serialize as bytes instead of string
      if type(_x) in [list, tuple]:
        buff.write(struct.pack('<I%sB'%length, length, *_x))
      else:
        buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_get_struct_3I().pack(_x.top_img.header.seq, _x.top_img.header.stamp.secs, _x.top_img.header.stamp.nsecs))
      _x = self.top_img.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_get_struct_2I().pack(_x.top_img.height, _x.top_img.width))
      _x = self.top_img.encoding
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_get_struct_BI().pack(_x.top_img.is_bigendian, _x.top_img.step))
      _x = self.top_img.data
      length = len(_x)
      # - if encoded as a list instead, serialize as bytes instead of string
      if type(_x) in [list, tuple]:
        buff.write(struct.pack('<I%sB'%length, length, *_x))
      else:
        buff.write(struct.pack('<I%ss'%length, length, _x))
      length = len(self.bot_img_boxes)
      buff.write(_struct_I.pack(length))
      for val1 in self.bot_img_boxes:
        _x = val1
        buff.write(_get_struct_4f().pack(_x.left, _x.top, _x.right, _x.bottom))
        _x = val1.id
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.pack('<I%ss'%length, length, _x))
      length = len(self.top_img_boxes)
      buff.write(_struct_I.pack(length))
      for val1 in self.top_img_boxes:
        _x = val1
        buff.write(_get_struct_4f().pack(_x.left, _x.top, _x.right, _x.bottom))
        _x = val1.id
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.pack('<I%ss'%length, length, _x))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      if self.bot_img is None:
        self.bot_img = sensor_msgs.msg.Image()
      if self.top_img is None:
        self.top_img = sensor_msgs.msg.Image()
      if self.bot_img_boxes is None:
        self.bot_img_boxes = None
      if self.top_img_boxes is None:
        self.top_img_boxes = None
      end = 0
      _x = self
      start = end
      end += 12
      (_x.bot_img.header.seq, _x.bot_img.header.stamp.secs, _x.bot_img.header.stamp.nsecs,) = _get_struct_3I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.bot_img.header.frame_id = str[start:end].decode('utf-8')
      else:
        self.bot_img.header.frame_id = str[start:end]
      _x = self
      start = end
      end += 8
      (_x.bot_img.height, _x.bot_img.width,) = _get_struct_2I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.bot_img.encoding = str[start:end].decode('utf-8')
      else:
        self.bot_img.encoding = str[start:end]
      _x = self
      start = end
      end += 5
      (_x.bot_img.is_bigendian, _x.bot_img.step,) = _get_struct_BI().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      self.bot_img.data = str[start:end]
      _x = self
      start = end
      end += 12
      (_x.top_img.header.seq, _x.top_img.header.stamp.secs, _x.top_img.header.stamp.nsecs,) = _get_struct_3I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.top_img.header.frame_id = str[start:end].decode('utf-8')
      else:
        self.top_img.header.frame_id = str[start:end]
      _x = self
      start = end
      end += 8
      (_x.top_img.height, _x.top_img.width,) = _get_struct_2I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.top_img.encoding = str[start:end].decode('utf-8')
      else:
        self.top_img.encoding = str[start:end]
      _x = self
      start = end
      end += 5
      (_x.top_img.is_bigendian, _x.top_img.step,) = _get_struct_BI().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      self.top_img.data = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.bot_img_boxes = []
      for i in range(0, length):
        val1 = custom_msgs.msg.Box()
        _x = val1
        start = end
        end += 16
        (_x.left, _x.top, _x.right, _x.bottom,) = _get_struct_4f().unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          val1.id = str[start:end].decode('utf-8')
        else:
          val1.id = str[start:end]
        self.bot_img_boxes.append(val1)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.top_img_boxes = []
      for i in range(0, length):
        val1 = custom_msgs.msg.Box()
        _x = val1
        start = end
        end += 16
        (_x.left, _x.top, _x.right, _x.bottom,) = _get_struct_4f().unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          val1.id = str[start:end].decode('utf-8')
        else:
          val1.id = str[start:end]
        self.top_img_boxes.append(val1)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_4f = None
def _get_struct_4f():
    global _struct_4f
    if _struct_4f is None:
        _struct_4f = struct.Struct("<4f")
    return _struct_4f
_struct_3I = None
def _get_struct_3I():
    global _struct_3I
    if _struct_3I is None:
        _struct_3I = struct.Struct("<3I")
    return _struct_3I
_struct_2I = None
def _get_struct_2I():
    global _struct_2I
    if _struct_2I is None:
        _struct_2I = struct.Struct("<2I")
    return _struct_2I
_struct_BI = None
def _get_struct_BI():
    global _struct_BI
    if _struct_BI is None:
        _struct_BI = struct.Struct("<BI")
    return _struct_BI
