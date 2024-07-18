run: build
	./build/moeka

setup:
	cmake \
		-G "Unix Makefiles" \
		-DCMAKE_BUILD_TYPE=Release \
		-DCMAKE_EXPORT_COMPILE_COMMANDS=1 \
		-DCMAKE_EXE_LINKER_FLAGS="-fuse-ld=mold" \
		-DCMAKE_SHARED_LINKER_FLAGS="-fuse-ld=mold" \
		-DTHIRD_PARTY_DIR=third_party -B build

build: setup
	cmake --build build -- -j16

