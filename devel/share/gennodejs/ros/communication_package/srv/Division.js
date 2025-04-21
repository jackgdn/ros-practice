// Auto-generated. Do not edit!

// (in-package communication_package.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------


//-----------------------------------------------------------

class DivisionRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.numerator = null;
      this.denominator = null;
    }
    else {
      if (initObj.hasOwnProperty('numerator')) {
        this.numerator = initObj.numerator
      }
      else {
        this.numerator = 0.0;
      }
      if (initObj.hasOwnProperty('denominator')) {
        this.denominator = initObj.denominator
      }
      else {
        this.denominator = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type DivisionRequest
    // Serialize message field [numerator]
    bufferOffset = _serializer.float64(obj.numerator, buffer, bufferOffset);
    // Serialize message field [denominator]
    bufferOffset = _serializer.float64(obj.denominator, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type DivisionRequest
    let len;
    let data = new DivisionRequest(null);
    // Deserialize message field [numerator]
    data.numerator = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [denominator]
    data.denominator = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 16;
  }

  static datatype() {
    // Returns string type for a service object
    return 'communication_package/DivisionRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '36144fd290b63c004c898a6d5631ab90';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64 numerator
    float64 denominator
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new DivisionRequest(null);
    if (msg.numerator !== undefined) {
      resolved.numerator = msg.numerator;
    }
    else {
      resolved.numerator = 0.0
    }

    if (msg.denominator !== undefined) {
      resolved.denominator = msg.denominator;
    }
    else {
      resolved.denominator = 0.0
    }

    return resolved;
    }
};

class DivisionResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.result = null;
      this.success = null;
    }
    else {
      if (initObj.hasOwnProperty('result')) {
        this.result = initObj.result
      }
      else {
        this.result = 0.0;
      }
      if (initObj.hasOwnProperty('success')) {
        this.success = initObj.success
      }
      else {
        this.success = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type DivisionResponse
    // Serialize message field [result]
    bufferOffset = _serializer.float64(obj.result, buffer, bufferOffset);
    // Serialize message field [success]
    bufferOffset = _serializer.bool(obj.success, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type DivisionResponse
    let len;
    let data = new DivisionResponse(null);
    // Deserialize message field [result]
    data.result = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [success]
    data.success = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 9;
  }

  static datatype() {
    // Returns string type for a service object
    return 'communication_package/DivisionResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'ead7e9fea50afbeb07b532762de132d2';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64 result
    bool success
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new DivisionResponse(null);
    if (msg.result !== undefined) {
      resolved.result = msg.result;
    }
    else {
      resolved.result = 0.0
    }

    if (msg.success !== undefined) {
      resolved.success = msg.success;
    }
    else {
      resolved.success = false
    }

    return resolved;
    }
};

module.exports = {
  Request: DivisionRequest,
  Response: DivisionResponse,
  md5sum() { return '40e9c5898eacc0da947d7d8e72bf20eb'; },
  datatype() { return 'communication_package/Division'; }
};
