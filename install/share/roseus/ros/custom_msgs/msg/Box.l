;; Auto-generated. Do not edit!


(when (boundp 'custom_msgs::Box)
  (if (not (find-package "CUSTOM_MSGS"))
    (make-package "CUSTOM_MSGS"))
  (shadow 'Box (find-package "CUSTOM_MSGS")))
(unless (find-package "CUSTOM_MSGS::BOX")
  (make-package "CUSTOM_MSGS::BOX"))

(in-package "ROS")
;;//! \htmlinclude Box.msg.html


(defclass custom_msgs::Box
  :super ros::object
  :slots (_left _top _right _bottom _id ))

(defmethod custom_msgs::Box
  (:init
   (&key
    ((:left __left) 0.0)
    ((:top __top) 0.0)
    ((:right __right) 0.0)
    ((:bottom __bottom) 0.0)
    ((:id __id) "")
    )
   (send-super :init)
   (setq _left (float __left))
   (setq _top (float __top))
   (setq _right (float __right))
   (setq _bottom (float __bottom))
   (setq _id (string __id))
   self)
  (:left
   (&optional __left)
   (if __left (setq _left __left)) _left)
  (:top
   (&optional __top)
   (if __top (setq _top __top)) _top)
  (:right
   (&optional __right)
   (if __right (setq _right __right)) _right)
  (:bottom
   (&optional __bottom)
   (if __bottom (setq _bottom __bottom)) _bottom)
  (:id
   (&optional __id)
   (if __id (setq _id __id)) _id)
  (:serialization-length
   ()
   (+
    ;; float32 _left
    4
    ;; float32 _top
    4
    ;; float32 _right
    4
    ;; float32 _bottom
    4
    ;; string _id
    4 (length _id)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _left
       (sys::poke _left (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _top
       (sys::poke _top (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _right
       (sys::poke _right (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _bottom
       (sys::poke _bottom (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; string _id
       (write-long (length _id) s) (princ _id s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _left
     (setq _left (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _top
     (setq _top (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _right
     (setq _right (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _bottom
     (setq _bottom (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; string _id
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _id (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(setf (get custom_msgs::Box :md5sum-) "eedc1c5a3505cba8031ed3005ed9af89")
(setf (get custom_msgs::Box :datatype-) "custom_msgs/Box")
(setf (get custom_msgs::Box :definition-)
      "float32 left
float32 top
float32 right
float32 bottom

string id
# the id should not be changed from 0 except for by the object prediction algorithm
")



(provide :custom_msgs/Box "eedc1c5a3505cba8031ed3005ed9af89")


