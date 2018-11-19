;; Auto-generated. Do not edit!


(when (boundp 'custom_msgs::Action)
  (if (not (find-package "CUSTOM_MSGS"))
    (make-package "CUSTOM_MSGS"))
  (shadow 'Action (find-package "CUSTOM_MSGS")))
(unless (find-package "CUSTOM_MSGS::ACTION")
  (make-package "CUSTOM_MSGS::ACTION"))

(in-package "ROS")
;;//! \htmlinclude Action.msg.html


(defclass custom_msgs::Action
  :super ros::object
  :slots (_id _params ))

(defmethod custom_msgs::Action
  (:init
   (&key
    ((:id __id) 0)
    ((:params __params) (make-array 0 :initial-element 0.0 :element-type :float))
    )
   (send-super :init)
   (setq _id (round __id))
   (setq _params __params)
   self)
  (:id
   (&optional __id)
   (if __id (setq _id __id)) _id)
  (:params
   (&optional __params)
   (if __params (setq _params __params)) _params)
  (:serialization-length
   ()
   (+
    ;; uint8 _id
    1
    ;; float32[] _params
    (* 4    (length _params)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _id
       (write-byte _id s)
     ;; float32[] _params
     (write-long (length _params) s)
     (dotimes (i (length _params))
       (sys::poke (elt _params i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _id
     (setq _id (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; float32[] _params
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _params (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _params i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     ))
   ;;
   self)
  )

(setf (get custom_msgs::Action :md5sum-) "12707864707374042b797df45f669e2c")
(setf (get custom_msgs::Action :datatype-) "custom_msgs/Action")
(setf (get custom_msgs::Action :definition-)
      "uint8 id
float32[] params

# The id codes are listed below
# 0 - scoop
# 1 - drive (left %, right %)
# 2 - stop
")



(provide :custom_msgs/Action "12707864707374042b797df45f669e2c")


