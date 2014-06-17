function(add_mpi_example example sources)
    add_executable(${example} ${sources})
    set_target_properties(${example} PROPERTIES
        COMPILE_FLAGS "${MPI_CXX_COMPILE_FLAGS}"
        LINK_FLAGS    "${MPI_CXX_LINK_FLAGS}"
        )
    target_link_libraries(${example}
        ${Boost_LIBRARIES}
        ${MPI_CXX_LIBRARIES}
        )
endfunction()

find_package(MPI QUIET)

if (MPI_CXX_FOUND)
    find_package(Boost COMPONENTS ${BOOST_COMPONENTS} mpi serialization)
    include_directories(${MPI_CXX_INCLUDE_PATH})
    add_mpi_example(deflated_cg deflated_cg.cpp)
endif()