set(IMAGE_DIFF_SOURCES
    ${IMAGE_DIFF_DIR}/gtk/ImageDiff.cpp
)

list(APPEND IMAGE_DIFF_INCLUDE_DIRECTORIES
    ${GTK3_INCLUDE_DIRS}
)

list(APPEND IMAGE_DIFF_LIBRARIES
    ${GTK3_LIBRARIES}
)