// Auto-generated. Do not edit!

// (in-package custom_msgs.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

let ImagesAndBoxes = require('../msg/ImagesAndBoxes.js');

//-----------------------------------------------------------

class ImagesAndBoxesSrvRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.skips = null;
    }
    else {
      if (initObj.hasOwnProperty('skips')) {
        this.skips = initObj.skips
      }
      else {
        this.skips = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ImagesAndBoxesSrvRequest
    // Serialize message field [skips]
    bufferOffset = _serializer.uint8(obj.skips, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ImagesAndBoxesSrvRequest
    let len;
    let data = new ImagesAndBoxesSrvRequest(null);
    // Deserialize message field [skips]
    data.skips = _deserializer.uint8(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 1;
  }

  static datatype() {
    // Returns string type for a service object
    return 'custom_msgs/ImagesAndBoxesSrvRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'ebafede1f57eb08796f2f3bba8184954';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    uint8 skips
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ImagesAndBoxesSrvRequest(null);
    if (msg.skips !== undefined) {
      resolved.skips = msg.skips;
    }
    else {
      resolved.skips = 0
    }

    return resolved;
    }
};

class ImagesAndBoxesSrvResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.result = null;
    }
    else {
      if (initObj.hasOwnProperty('result')) {
        this.result = initObj.result
      }
      else {
        this.result = new ImagesAndBoxes();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ImagesAndBoxesSrvResponse
    // Serialize message field [result]
    bufferOffset = ImagesAndBoxes.serialize(obj.result, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ImagesAndBoxesSrvResponse
    let len;
    let data = new ImagesAndBoxesSrvResponse(null);
    // Deserialize message field [result]
    data.result = ImagesAndBoxes.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += ImagesAndBoxes.getMessageSize(object.result);
    return length;
  }

  static datatype() {
    // Returns string type for a service object
    return 'custom_msgs/ImagesAndBoxesSrvResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '31a9f53ef2b7ebb39f949a9de81ba211';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    custom_msgs/ImagesAndBoxes result
    
    ================================================================================
    MSG: custom_msgs/ImagesAndBoxes
    sensor_msgs/Image bot_img
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
    # the id should not be changed from 0 except for by the object prediction algorithm
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ImagesAndBoxesSrvResponse(null);
    if (msg.result !== undefined) {
      resolved.result = ImagesAndBoxes.Resolve(msg.result)
    }
    else {
      resolved.result = new ImagesAndBoxes()
    }

    return resolved;
    }
};

module.exports = {
  Request: ImagesAndBoxesSrvRequest,
  Response: ImagesAndBoxesSrvResponse,
  md5sum() { return '5d7f9b966106cb762e276fc9ad963134'; },
  datatype() { return 'custom_msgs/ImagesAndBoxesSrv'; }
};
