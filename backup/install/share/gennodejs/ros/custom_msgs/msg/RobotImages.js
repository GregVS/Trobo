// Auto-generated. Do not edit!

// (in-package custom_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let sensor_msgs = _finder('sensor_msgs');

//-----------------------------------------------------------

class RobotImages {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.bot_img = null;
      this.top_img = null;
    }
    else {
      if (initObj.hasOwnProperty('bot_img')) {
        this.bot_img = initObj.bot_img
      }
      else {
        this.bot_img = new sensor_msgs.msg.Image();
      }
      if (initObj.hasOwnProperty('top_img')) {
        this.top_img = initObj.top_img
      }
      else {
        this.top_img = new sensor_msgs.msg.Image();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type RobotImages
    // Serialize message field [bot_img]
    bufferOffset = sensor_msgs.msg.Image.serialize(obj.bot_img, buffer, bufferOffset);
    // Serialize message field [top_img]
    bufferOffset = sensor_msgs.msg.Image.serialize(obj.top_img, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type RobotImages
    let len;
    let data = new RobotImages(null);
    // Deserialize message field [bot_img]
    data.bot_img = sensor_msgs.msg.Image.deserialize(buffer, bufferOffset);
    // Deserialize message field [top_img]
    data.top_img = sensor_msgs.msg.Image.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += sensor_msgs.msg.Image.getMessageSize(object.bot_img);
    length += sensor_msgs.msg.Image.getMessageSize(object.top_img);
    return length;
  }

  static datatype() {
    // Returns string type for a message object
    return 'custom_msgs/RobotImages';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '54e3756641edd5f5344850f8fdb6eba6';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    sensor_msgs/Image bot_img
    sensor_msgs/Image top_img
    
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
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new RobotImages(null);
    if (msg.bot_img !== undefined) {
      resolved.bot_img = sensor_msgs.msg.Image.Resolve(msg.bot_img)
    }
    else {
      resolved.bot_img = new sensor_msgs.msg.Image()
    }

    if (msg.top_img !== undefined) {
      resolved.top_img = sensor_msgs.msg.Image.Resolve(msg.top_img)
    }
    else {
      resolved.top_img = new sensor_msgs.msg.Image()
    }

    return resolved;
    }
};

module.exports = RobotImages;
