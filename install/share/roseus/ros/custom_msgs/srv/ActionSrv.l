;; Auto-generated. Do not edit!


(when (boundp 'custom_msgs::ActionSrv)
  (if (not (find-package "CUSTOM_MSGS"))
    (make-package "CUSTOM_MSGS"))
  (shadow 'ActionSrv (find-package "CUSTOM_MSGS")))
(unless (find-package "CUSTOM_MSGS::ACTIONSRV")
  (make-package "CUSTOM_MSGS::ACTIONSRV"))
(unless (find-package "CUSTOM_MSGS::ACTIONSRVREQUEST")
  (make-package "CUSTOM_MSGS::ACTIONSRVREQUEST"))
(unless (find-package "CUSTOM_MSGS::ACTIONSRVRESPONSE")
  (make-package "CUSTOM_MSGS::ACTIONSRVRESPONSE"))

(in-package "ROS")





(defclass custom_msgs::ActionSrvRequest
  :super ros::object
  :slots (_skips ))

(defmethod custom_msgs::ActionSrvRequest
  (:init
   (&key
    ((:skips __skips) 0)
    )
   (send-super :init)
   (setq _skips (round __skips))
   self)
  (:skips
   (&optional __skips)
   (if __skips (setq _skips __skips)) _skips)
  (:serialization-length
   ()
   (+
    ;; uint8 _skips
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _skips
       (write-byte _skips s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _skips
     (setq _skips (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(defclass custom_msgs::ActionSrvResponse
  :super ros::object
  :slots (_result ))

(defmethod custom_msgs::ActionSrvResponse
  (:init
   (&key
    ((:result __result) (instance custom_msgs::Action :init))
    )
   (send-super :init)
   (setq _result __result)
   self)
  (:result
   (&rest __result)
   (if (keywordp (car __result))
       (send* _result __result)
     (progn
       (if __result (setq _result (car __result)))
       _result)))
  (:serialization-length
   ()
   (+
    ;; custom_msgs/Action _result
    (send _result :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; custom_msgs/Action _result
       (send _result :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; custom_msgs/Action _result
     (send _result :deserialize buf ptr-) (incf ptr- (send _result :serialization-length))
   ;;
   self)
  )

(defclass custom_msgs::ActionSrv
  :super ros::object
  :slots ())

(setf (get custom_msgs::ActionSrv :md5sum-) "bc83a7ef89bbba9a6fa9c799fab90d6c")
(setf (get custom_msgs::ActionSrv :datatype-) "custom_msgs/ActionSrv")
(setf (get custom_msgs::ActionSrv :request) custom_msgs::ActionSrvRequest)
(setf (get custom_msgs::ActionSrv :response) custom_msgs::ActionSrvResponse)

(defmethod custom_msgs::ActionSrvRequest
  (:response () (instance custom_msgs::ActionSrvResponse :init)))

(setf (get custom_msgs::ActionSrvRequest :md5sum-) "bc83a7ef89bbba9a6fa9c799fab90d6c")
(setf (get custom_msgs::ActionSrvRequest :datatype-) "custom_msgs/ActionSrvRequest")
(setf (get custom_msgs::ActionSrvRequest :definition-)
      "uint8 skips
---
custom_msgs/Action result

================================================================================
MSG: custom_msgs/Action
uint8 id
float32[] params

# The id codes are listed below
# 0 - scoop
# 1 - drive (left %, right %)
")

(setf (get custom_msgs::ActionSrvResponse :md5sum-) "bc83a7ef89bbba9a6fa9c799fab90d6c")
(setf (get custom_msgs::ActionSrvResponse :datatype-) "custom_msgs/ActionSrvResponse")
(setf (get custom_msgs::ActionSrvResponse :definition-)
      "uint8 skips
---
custom_msgs/Action result

================================================================================
MSG: custom_msgs/Action
uint8 id
float32[] params

# The id codes are listed below
# 0 - scoop
# 1 - drive (left %, right %)
")



(provide :custom_msgs/ActionSrv "bc83a7ef89bbba9a6fa9c799fab90d6c")


