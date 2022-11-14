#
#  Be sure to run `pod spec lint ZHMacroTools,podspec.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |s|

  s.name         = "ZHMacroTools"
  s.version      = "1.0.0"
  s.summary      = "this is iOS objc macro tools"
  s.description  = <<-DESC 'ZHMacroTools'
                   DESC
  s.homepage     = "https://github.com/number-62/ZHMacroTools.git"

  s.license      = "MIT"

  s.author       = { "zhl" => "z779215878@gmail.com" }

  s.platform     = :ios

  s.ios.deployment_target = "9.0"

  s.source       = { :git => "https://github.com/number-62/ZHMacroTools.git", :tag => "v#{s.version}" }

  s.source_files = 'ZHMacroTools/*'

  s.frameworks   = 'Foundation', 'UIKit'

  s.requires_arc = true

end
