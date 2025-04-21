; Auto-generated. Do not edit!


(cl:in-package communication_package-srv)


;//! \htmlinclude Division-request.msg.html

(cl:defclass <Division-request> (roslisp-msg-protocol:ros-message)
  ((numerator
    :reader numerator
    :initarg :numerator
    :type cl:float
    :initform 0.0)
   (denominator
    :reader denominator
    :initarg :denominator
    :type cl:float
    :initform 0.0))
)

(cl:defclass Division-request (<Division-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Division-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Division-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name communication_package-srv:<Division-request> is deprecated: use communication_package-srv:Division-request instead.")))

(cl:ensure-generic-function 'numerator-val :lambda-list '(m))
(cl:defmethod numerator-val ((m <Division-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader communication_package-srv:numerator-val is deprecated.  Use communication_package-srv:numerator instead.")
  (numerator m))

(cl:ensure-generic-function 'denominator-val :lambda-list '(m))
(cl:defmethod denominator-val ((m <Division-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader communication_package-srv:denominator-val is deprecated.  Use communication_package-srv:denominator instead.")
  (denominator m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Division-request>) ostream)
  "Serializes a message object of type '<Division-request>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'numerator))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'denominator))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Division-request>) istream)
  "Deserializes a message object of type '<Division-request>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'numerator) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'denominator) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Division-request>)))
  "Returns string type for a service object of type '<Division-request>"
  "communication_package/DivisionRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Division-request)))
  "Returns string type for a service object of type 'Division-request"
  "communication_package/DivisionRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Division-request>)))
  "Returns md5sum for a message object of type '<Division-request>"
  "40e9c5898eacc0da947d7d8e72bf20eb")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Division-request)))
  "Returns md5sum for a message object of type 'Division-request"
  "40e9c5898eacc0da947d7d8e72bf20eb")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Division-request>)))
  "Returns full string definition for message of type '<Division-request>"
  (cl:format cl:nil "float64 numerator~%float64 denominator~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Division-request)))
  "Returns full string definition for message of type 'Division-request"
  (cl:format cl:nil "float64 numerator~%float64 denominator~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Division-request>))
  (cl:+ 0
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Division-request>))
  "Converts a ROS message object to a list"
  (cl:list 'Division-request
    (cl:cons ':numerator (numerator msg))
    (cl:cons ':denominator (denominator msg))
))
;//! \htmlinclude Division-response.msg.html

(cl:defclass <Division-response> (roslisp-msg-protocol:ros-message)
  ((result
    :reader result
    :initarg :result
    :type cl:float
    :initform 0.0)
   (success
    :reader success
    :initarg :success
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass Division-response (<Division-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Division-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Division-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name communication_package-srv:<Division-response> is deprecated: use communication_package-srv:Division-response instead.")))

(cl:ensure-generic-function 'result-val :lambda-list '(m))
(cl:defmethod result-val ((m <Division-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader communication_package-srv:result-val is deprecated.  Use communication_package-srv:result instead.")
  (result m))

(cl:ensure-generic-function 'success-val :lambda-list '(m))
(cl:defmethod success-val ((m <Division-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader communication_package-srv:success-val is deprecated.  Use communication_package-srv:success instead.")
  (success m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Division-response>) ostream)
  "Serializes a message object of type '<Division-response>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'result))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'success) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Division-response>) istream)
  "Deserializes a message object of type '<Division-response>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'result) (roslisp-utils:decode-double-float-bits bits)))
    (cl:setf (cl:slot-value msg 'success) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Division-response>)))
  "Returns string type for a service object of type '<Division-response>"
  "communication_package/DivisionResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Division-response)))
  "Returns string type for a service object of type 'Division-response"
  "communication_package/DivisionResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Division-response>)))
  "Returns md5sum for a message object of type '<Division-response>"
  "40e9c5898eacc0da947d7d8e72bf20eb")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Division-response)))
  "Returns md5sum for a message object of type 'Division-response"
  "40e9c5898eacc0da947d7d8e72bf20eb")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Division-response>)))
  "Returns full string definition for message of type '<Division-response>"
  (cl:format cl:nil "float64 result~%bool success~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Division-response)))
  "Returns full string definition for message of type 'Division-response"
  (cl:format cl:nil "float64 result~%bool success~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Division-response>))
  (cl:+ 0
     8
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Division-response>))
  "Converts a ROS message object to a list"
  (cl:list 'Division-response
    (cl:cons ':result (result msg))
    (cl:cons ':success (success msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'Division)))
  'Division-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'Division)))
  'Division-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Division)))
  "Returns string type for a service object of type '<Division>"
  "communication_package/Division")