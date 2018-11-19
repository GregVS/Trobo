; Auto-generated. Do not edit!


(cl:in-package custom_msgs-msg)


;//! \htmlinclude Action.msg.html

(cl:defclass <Action> (roslisp-msg-protocol:ros-message)
  ((id
    :reader id
    :initarg :id
    :type cl:fixnum
    :initform 0)
   (params
    :reader params
    :initarg :params
    :type (cl:vector cl:float)
   :initform (cl:make-array 0 :element-type 'cl:float :initial-element 0.0)))
)

(cl:defclass Action (<Action>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Action>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Action)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name custom_msgs-msg:<Action> is deprecated: use custom_msgs-msg:Action instead.")))

(cl:ensure-generic-function 'id-val :lambda-list '(m))
(cl:defmethod id-val ((m <Action>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msgs-msg:id-val is deprecated.  Use custom_msgs-msg:id instead.")
  (id m))

(cl:ensure-generic-function 'params-val :lambda-list '(m))
(cl:defmethod params-val ((m <Action>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msgs-msg:params-val is deprecated.  Use custom_msgs-msg:params instead.")
  (params m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Action>) ostream)
  "Serializes a message object of type '<Action>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'id)) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'params))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'params))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Action>) istream)
  "Deserializes a message object of type '<Action>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'id)) (cl:read-byte istream))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'params) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'params)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits))))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Action>)))
  "Returns string type for a message object of type '<Action>"
  "custom_msgs/Action")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Action)))
  "Returns string type for a message object of type 'Action"
  "custom_msgs/Action")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Action>)))
  "Returns md5sum for a message object of type '<Action>"
  "12707864707374042b797df45f669e2c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Action)))
  "Returns md5sum for a message object of type 'Action"
  "12707864707374042b797df45f669e2c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Action>)))
  "Returns full string definition for message of type '<Action>"
  (cl:format cl:nil "uint8 id~%float32[] params~%~%# The id codes are listed below~%# 0 - scoop~%# 1 - drive (left %, right %)~%# 2 - stop~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Action)))
  "Returns full string definition for message of type 'Action"
  (cl:format cl:nil "uint8 id~%float32[] params~%~%# The id codes are listed below~%# 0 - scoop~%# 1 - drive (left %, right %)~%# 2 - stop~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Action>))
  (cl:+ 0
     1
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'params) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Action>))
  "Converts a ROS message object to a list"
  (cl:list 'Action
    (cl:cons ':id (id msg))
    (cl:cons ':params (params msg))
))
