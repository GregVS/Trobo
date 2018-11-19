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

let Action = require('../msg/Action.js');

//-----------------------------------------------------------

class ActionSrvRequest {
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
    // Serializes a message object of type ActionSrvRequest
    // Serialize message field [skips]
    bufferOffset = _serializer.uint8(obj.skips, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ActionSrvRequest
    let len;
    let data = new ActionSrvRequest(null);
    // Deserialize message field [skips]
    data.skips = _deserializer.uint8(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 1;
  }

  static datatype() {
    // Returns string type for a service object
    return 'custom_msgs/ActionSrvRequest';
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
    const resolved = new ActionSrvRequest(null);
    if (msg.skips !== undefined) {
      resolved.skips = msg.skips;
    }
    else {
      resolved.skips = 0
    }

    return resolved;
    }
};

class ActionSrvResponse {
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
        this.result = new Action();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ActionSrvResponse
    // Serialize message field [result]
    bufferOffset = Action.serialize(obj.result, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ActionSrvResponse
    let len;
    let data = new ActionSrvResponse(null);
    // Deserialize message field [result]
    data.result = Action.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += Action.getMessageSize(object.result);
    return length;
  }

  static datatype() {
    // Returns string type for a service object
    return 'custom_msgs/ActionSrvResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'e80c7b45afea0457eeb6cf7c0177651c';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    custom_msgs/Action result
    
    ================================================================================
    MSG: custom_msgs/Action
    uint8 id
    float32[] params
    
    # The id codes are listed below
    # 0 - scoop
    # 1 - drive (left %, right %)
    # 2 - stop
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ActionSrvResponse(null);
    if (msg.result !== undefined) {
      resolved.result = Action.Resolve(msg.result)
    }
    else {
      resolved.result = new Action()
    }

    return resolved;
    }
};

module.exports = {
  Request: ActionSrvRequest,
  Response: ActionSrvResponse,
  md5sum() { return 'bc83a7ef89bbba9a6fa9c799fab90d6c'; },
  datatype() { return 'custom_msgs/ActionSrv'; }
};
