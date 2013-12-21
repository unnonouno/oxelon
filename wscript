import Options

VERSION='0.0.1'
APPNAME='oxelon'

def options(opt):
  opt.load('compiler_cxx')
  opt.load('unittest_gtest')

  opt.add_option('--enable-gcov',
                 action='store_true',
                 default=False,
                 dest='gcov',
                 help='only for debug')

def configure(conf):
  conf.env.CXXFLAGS += ['-O2', '-Wall', '-g', '-pipe']
  conf.load('compiler_cxx')
  conf.load('unittest_gtest')

  # conf.check_cfg(package = 'pficommon', args = '--cflags --libs')
  # conf.check_cxx(lib='libname', header_name = 'header.h')

  if Options.options.gcov:
    conf.env.append_value('CXXFLAGS', '-fprofile-arcs')
    conf.env.append_value('CXXFLAGS', '-ftest-coverage')
    conf.env.append_value('LINKFLAGS', '-lgcov')
    conf.env.append_value('LINKFLAGS', '-fprofile-arcs')
    conf.env.append_value('LINKFLAGS', '-ftest-coverage')
    #conf.env.append_value('LINKFLAGS', '-lprofile_rt')

def build(bld):
  bld.recurse('src')
