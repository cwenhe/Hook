include_guard()

#######some function
## generated static libary path
function(set_archive_path dst_path)
    if(WIN32)
        set_target_properties(${PROJECT_NAME} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "$<IF:$<CONFIG:Debug>,${dst_path},${dst_path}>")
    else()
        set_target_properties(${PROJECT_NAME} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${dst_path})
    endif()
endfunction()

## generated exe and dll path
function(set_runfile_path dst_path)
    if(WIN32)
        set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "$<IF:$<CONFIG:Debug>,${dst_path},${dst_path}>")
    else()
        set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTOTY ${dst_path})
    endif()
endfunction()

## 
function(generate_boost_lib lib_names dst)
    if(WIN32)
        foreach( lib_name ${lib_names})
            set(lib_tmp lib${lib_name}-vc$(PlatformToolsetVersion)-mt-$<$<CONFIG:Debug>:gd->${BOOST_VERSION} ${lib_tmp})
        endforeach()
    else()
        foreach( lib_name ${lib_names})
            set(lib_tmp ${lib_tmp} ${lib_name})
        endforeach()
    endif()
    set(${dst} ${lib_tmp} PARENT_SCOPE)
endfunction()

function(generate_gen_lib lib_names dst post_debug_fix)
    if(WIN32)
        foreach( lib_name ${lib_names})
            set(lib_tmp ${lib_name}$<$<CONFIG:Debug>:${post_debug_fix}> ${lib_tmp})
        endforeach()
    else()
        foreach( lib_name ${lib_names})
            set(lib_tmp ${lib_tmp} ${lib_name})
        endforeach()
    endif()
    set(${dst} ${lib_tmp} PARENT_SCOPE)
endfunction()

