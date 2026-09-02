
configure_file(applications/zeit.desktop
	       ${CMAKE_CURRENT_BINARY_DIR}/zeit.desktop @ONLY)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/zeit.desktop
	DESTINATION ${CMAKE_INSTALL_DATADIR}/applications)
install(DIRECTORY pixmaps DESTINATION share)
install(FILES pixmaps/zeit.xpm
	DESTINATION ${CMAKE_INSTALL_DATADIR}/icons/hicolor/32x32/apps)
#install(DIRECTORY man DESTINATION share)
