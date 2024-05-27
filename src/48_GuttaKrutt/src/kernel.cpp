
extern "C"{
    #include "libc/system.h"
    // #include "memory/memory.h"
    #include "common.h"
    // #include "interrupts.h"
    // #include "input.h"
    // #include "song/song.h"
}

/*
// Existing global operators new overloads for C++.
void* operator new(size_t size){
    return malloc(size);
}

void* operator new[](size_t size){
    return malloc(size);
}

// Existing global operators delete overloads for C++.
void operator delete(void* p) noexcept{
    free(p);
}

void operator delete[](void* p) noexcept{
    free(p);
}

// Add-sized deallocation functions for C++.
void operator delete(void* p, size_t size) noexcept{
    (void)size; // size is not needed for deallocation, added to match the signature.
    free(p);
}

void operator delete[](void* p, size_t size) noexcept{
    (void)size; // size is not needed for deallocation, added to match the signature.
    free(p);
}

SongPlayer* create_song_player(){
    auto* player = new SongPlayer();
    player->play_song = play_song_impl;
    return player;
}

*/

extern "C" int kernel_main(void);
int kernel_main(){

    /*
    // Set up interrupt handlers
    register_interrupt_handler(3, [](registers_t* regs, void* context) {
        printf("Interrupt 3 - OK\n");
    }, NULL);

    register_interrupt_handler(4, [](registers_t* regs, void* context) {
        printf("Interrupt 4 - OK\n");
    }, NULL);

    register_interrupt_handler(14, [](registers_t* regs, void* context) {
        uint32_t faulting_address;
        __asm__ __volatile__("mov %%cr2, %0" : "=r" (faulting_address));

        int32_t present = !(regs->err_code & 0x1); // Page not present
        int32_t rw = regs->err_code & 0x2;           // Write operation?
        int32_t us = regs->err_code & 0x4;           // Processor was in user-mode?
        int32_t reserved = regs->err_code & 0x8;     // Overwritten CPU-reserved bits of page entry?
        int32_t id = regs->err_code & 0x10;          // Caused by an instruction fetch?

        printf("Page fault! ("); 
        if (present)
            printf("present");
        if (rw)
            printf("read-only");
        if (us)
            printf("user-mode");
        if (reserved)
            printf("reserved");
        printf(")\n\n");
    }, NULL);

    // Trigger interrupts to test the handlers
    asm volatile("int $0x3");
    asm volatile("int $0x4");

    // Enable interrupts
    asm volatile("sti");

    // Register IRQ handler for keyboard (IRQ1)
    register_irq_handler(IRQ1, [](registers_t*, void*) {
        // Read from the keyboard
        unsigned char scancode = inb(0x60);
        char f = scancode_to_ascii(&scancode);

        // Print the character
        printf("%c", f);

        // Acknowledge the IRQ
        asm volatile("cli");
    }, NULL);

    // Define songs
    Song* songs[] = {
        new Song({battlefield_1942_theme, sizeof(battlefield_1942_theme) / sizeof(Note)}),
        new Song({tetris_theme, sizeof(tetris_theme) / sizeof(Note)}),
        new Song({mii_theme, sizeof(mii_theme) / sizeof(Note)}),
        new Song({megalovania, sizeof(megalovania) / sizeof(Note)}),
        new Song({mario_bros, sizeof(mario_bros) / sizeof(Note)}),
        new Song({mario_underworld, sizeof(mario_underworld) / sizeof(Note)}),
        new Song({mario_star, sizeof(mario_star) / sizeof(Note)}),
        new Song({mario_death, sizeof(mario_death) / sizeof(Note)}),
    };

    // Number of songs
    uint32_t n_songs = sizeof(songs) / sizeof(Song*);

    // Create a song player and play each song
    SongPlayer* player = create_song_player();
    for (uint32_t i = 0; i < n_songs; i++)
    {
        printf("Playing song %d\n", i);
        player->play_song(songs[i]);
        printf("Song %d done\n", i);
    }
    */

    // Main loop
    printf("Kernel main loop\n");
    while (true)
    {
        // Kernel main tasks
    }
    //  This part of the code will never be reached
    printf("Done!!!\n");
    return 0;
}