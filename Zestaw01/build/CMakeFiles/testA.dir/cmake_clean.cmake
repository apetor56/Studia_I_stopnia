file(REMOVE_RECURSE
  "../out/testA.exe"
  "../out/testA.exe.manifest"
  "../out/testA.pdb"
  "CMakeFiles/testA.dir/src/testA.cpp.obj"
  "CMakeFiles/testA.dir/src/testA.cpp.obj.d"
  "libtestA.dll.a"
)

# Per-language clean rules from dependency scanning.
foreach(lang CXX)
  include(CMakeFiles/testA.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
