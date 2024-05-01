set(VCPKG_TARGET_ARCHITECTURE x64)
set(VCPKG_CRT_LINKAGE dynamic)
set(VCPKG_LIBRARY_LINKAGE dynamic)
set(VCPKG_BUILD_TYPE release)

if(PORT MATCHES "secp256k1")
    set(VCPKG_LIBRARY_LINKAGE static)
endif()