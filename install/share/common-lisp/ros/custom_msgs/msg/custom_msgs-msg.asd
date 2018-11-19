
(cl:in-package :asdf)

(defsystem "custom_msgs-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :sensor_msgs-msg
)
  :components ((:file "_package")
    (:file "Action" :depends-on ("_package_Action"))
    (:file "_package_Action" :depends-on ("_package"))
    (:file "Box" :depends-on ("_package_Box"))
    (:file "_package_Box" :depends-on ("_package"))
    (:file "ImagesAndBoxes" :depends-on ("_package_ImagesAndBoxes"))
    (:file "_package_ImagesAndBoxes" :depends-on ("_package"))
    (:file "PredictionBoxes" :depends-on ("_package_PredictionBoxes"))
    (:file "_package_PredictionBoxes" :depends-on ("_package"))
    (:file "RobotImages" :depends-on ("_package_RobotImages"))
    (:file "_package_RobotImages" :depends-on ("_package"))
  ))