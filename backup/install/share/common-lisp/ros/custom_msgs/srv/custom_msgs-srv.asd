
(cl:in-package :asdf)

(defsystem "custom_msgs-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :custom_msgs-msg
)
  :components ((:file "_package")
    (:file "ActionSrv" :depends-on ("_package_ActionSrv"))
    (:file "_package_ActionSrv" :depends-on ("_package"))
    (:file "ImagesAndBoxesSrv" :depends-on ("_package_ImagesAndBoxesSrv"))
    (:file "_package_ImagesAndBoxesSrv" :depends-on ("_package"))
  ))