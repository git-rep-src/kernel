void kmain(void)
{
	const char *str = " OK ";
	char *vga_buffer = (char *)0xb8000; // video buffer pointer.
	unsigned int i = 0;
	unsigned int j = 0;

    // clean screen
	while(j < 80 * 25 * 2) {
		vga_buffer[j] = ' '; // blank
        vga_buffer[j + 1] = 0x07; // color
		j = j + 2;
	}

	j = 0;

	// writes string
	while(str[j] != '\0') {
		vga_buffer[i] = str[j]; // character
		vga_buffer[i + 1] = 0x87; // color
		++j;
		i = i + 2;
	}

	return;
}
