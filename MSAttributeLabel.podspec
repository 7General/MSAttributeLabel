

Pod::Spec.new do |s|
  s.name             = 'MSAttributeLabel'
  s.version          = '0.1.0'
  s.summary          = 'A short description of MSAttributeLabel.'



  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://github.com/7General'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'huizhou.wang' => 'hhh.@163.com' }
  s.source           = { :git => 'https://github.com/7General/MSAttributeLabel.git', :tag => s.version.to_s }

  s.ios.deployment_target = '10.0'

  s.source_files = 'MSAttributeLabel/Classes/**/*'
  
  
end
