add_rules("mode.debug", "mode.release")

set_languages("c++20")
set_warnings("allextra")

target("elecsim")
	set_kind("binary")
	add_headerfiles("Sources/*.hpp", "Sources/*.tpp")
	add_files("Sources/*.cpp")

	if is_mode("release") then
		set_options("-Ofast")
	end

	after_build(function (target)
		os.exec("cp %s %s", target:targetfile(), target:name())
	end)