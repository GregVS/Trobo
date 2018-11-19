// Auto-generated. Do not edit!

// (in-package custom_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class Box {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.left = null;
      this.top = null;
      this.right = null;
      this.bottom = null;
      this.id = null;
    }
    else {
      if (initObj.hasOwnProperty('left')) {
        this.left = initObj.left
      }
      else {
        this.left = 0.0;
      }
      if (initObj.hasOwnProperty('top')) {
        this.top = initObj.top
      }
      else {
        this.top = 0.0;
      }
      if (initObj.hasOwnProperty('right')) {
        this.right = initObj.right
      }
      else {
        this.right = 0.0;
      }
      if (initObj.hasOwnProperty('bottom')) {
        this.bottom = initObj.bottom
      }
      else {
        this.bottom = 0.0;
      }
      if (initObj.hasOwnProperty('id')) {
        this.id = initObj.id
      }
      else {
        this.id = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Box
    // Serialize message field [left]
    bufferOffset = _serializer.float32(obj.left, buffer, bufferOffset);
    // Serialize message field [top]
    bufferOffset = _serializer.float32(obj.top, buffer, bufferOffset);
    // Serialize message field [right]
    bufferOffset = _serializer.float32(obj.right, buffer, bufferOffset);
    // Serialize message field [bottom]
    bufferOffset = _serializer.float32(obj.bottom, buffer, bufferOffset);
    // Serialize message field [id]
    bufferOffset = _serializer.string(obj.id, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Box
    let len;
    let data = new Box(null);
    // Deserialize message field [left]
    data.left = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [top]
    data.top = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [right]
    data.right = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [bottom]
    data.bottom = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [id]
    data.id = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.id.length;
    return length + 20;
  }

  static datatype() {
    // Returns string type for a message object
    return 'custom_msgs/Box';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'eedc1c5a3505cba8031ed3005ed9af89';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
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
    const resolved = new Box(null);
    if (msg.left !== undefined) {
      resolved.left = msg.left;
    }
    else {
      resolved.left = 0.0
    }

    if (msg.top !== undefined) {
      resolved.top = msg.top;
    }
    else {
      resolved.top = 0.0
    }

    if (msg.right !== undefined) {
      resolved.right = msg.right;
    }
    else {
      resolved.right = 0.0
    }

    if (msg.bottom !== undefined) {
      resolved.bottom = msg.bottom;
    }
    else {
      resolved.bottom = 0.0
    }

    if (msg.id !== undefined) {
      resolved.id = msg.id;
    }
    else {
      resolved.id = ''
    }

    return resolved;
    }
};

module.exports = Box;
