find_package(GitInfo REQUIRED)

if(GIT_FOUND)
    git_wc_info(${PROJECT_SOURCE_DIR} AEGISUB)

    string(LENGTH AEGISUB_WC_LATEST_TAG TAG_LENGTH)
    if(${AEGISUB_WC_LATEST_TAG} MATCHES "fatal.+")
        set(AEGISUB_WC_LATEST_TAG "unknown_version")
    elseif(${AEGISUB_WC_LATEST_TAG} MATCHES "v.+" AND TAG_LENGTH GREATER 1) # remove leading "v"
        string(SUBSTRING ${AEGISUB_WC_LATEST_TAG} 1 -1 AEGISUB_WC_LATEST_TAG)
    endif()

    set(GIT_VERSION_NUMBER -1)

    if(${AEGISUB_WC_LATEST_TAG} MATCHES "([0-9]+)\\.([0-9]+)\\.([0-9]+)")
        set(GIT_VERSION_MAJOR ${CMAKE_MATCH_1})
        set(GIT_VERSION_MINOR ${CMAKE_MATCH_2})
        set(GIT_VERSION_PATCH ${CMAKE_MATCH_3})
        math(EXPR GIT_VERSION_NUMBER "${GIT_VERSION_MAJOR}*100000+${GIT_VERSION_MINOR}*1000+${GIT_VERSION_PATCH}")
    else()
        message(STATUS "Aegisub Build: The latest tag doesn't match x.x.x!!!")
        set(GIT_VERSION_MAJOR 0)
        set(GIT_VERSION_MINOR 0)
        set(GIT_VERSION_PATCH 0)
        if(${AEGISUB_WC_LATEST_TAG} MATCHES "([0-9]+)")
            set(GIT_VERSION_NUMBER ${CMAKE_MATCH_1})
        endif()
    endif()

    set(TAGGED_RELEASE OFF)
    if(${AEGISUB_WC_LATEST_TAG} STREQUAL "unknown_version")
        message(STATUS "Aegisub Build: Couldn't find any tag information...")
        set(VERSION_STRING "unknown_version")
        set(INSTALLER_VERSION_STRING "unknown_version")
    elseif(AEGISUB_WC_LATEST_TAG_LONG MATCHES ".+-[0-9]+-g.+")
    message(STATUS "Aegisub Build: Not a release commit...")
        string(SUBSTRING ${AEGISUB_WC_REVISION_HASH} 0 8 AEGISUB_WC_REVISION_HASH_SHORT)
        set(VERSION_STRING "${AEGISUB_WC_BRANCH_NAME}-${AEGISUB_WC_REVISION_HASH_SHORT}")
        set(INSTALLER_VERSION_STRING ${AEGISUB_WC_LATEST_TAG})
    else()
        message(STATUS "Aegisub Build: Detected Git tag, flagging as release...")
        set(TAGGED_RELEASE ON)
        set(VERSION_STRING ${AEGISUB_WC_LATEST_TAG})
        set(INSTALLER_VERSION_STRING ${AEGISUB_WC_LATEST_TAG})
    endif()
else()
    set(BUILD_GIT_VERSION_NUMBER -1)
    set(VERSION_STRING "unknown_version")
    set(INSTALLER_VERSION_STRING "unknown_version")
    set(TAGGED_RELEASE OFF)
    set(GIT_VERSION_MAJOR 0)
    set(GIT_VERSION_MINOR 0)
    set(GIT_VERSION_PATCH 0)
endif()

configure_file(build/cmake/git_version.h.in src/generated/git_version.h)
