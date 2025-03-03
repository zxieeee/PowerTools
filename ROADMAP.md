# First Alpha Release Notice

We are preparing to release our first alpha realease. We implemented the core logic for organising files within a folder or if you want now you can establish a relationship with entirely different folders.




# Goals

- [ ] Program as a daemon or a service.
  - [x] read from a config.conf file where some config like
  - [x] folder or folders (could be Desktop and Downloads folder or much more) where our program will work( contains data about a directory )
  - [ ] add a delay timer for program ( if possible implement OS specific APIs using inotify and ReadDirectoryChangesW in code itself so that we can deprecate this variable in future)
  - [x] a map that contains folders and extension check the .conf file example
  - [ ] config reorganisation for sensible human readable format 💡

---

- [ ] GUI
  - [ ] config.conf file Generation with the name config.conf under a folder in platforms respective preferred config location
  - [ ] implementing User preferred folders ( do give an option to let the user choose using the respective platform filepicker APIs)
  - [ ] Implementing Stop and Start(saves config and restart) button for the running status of service
  - [ ] Support for themes light dark or native and accent color

---

- [ ] Code 🏆

  - [ ] config file generation after reading data from GTKTEXTVIEW and other VARIABLES (gui has lots of work to do so things may change)
  - [ ] First Read from the config.conf file
  - [x] the runs the directory iterator and if file found of some name and extension place it in their respective place and then wait for the native APIs to give you signal that some file is changed in file system.
  - [x] then a movefiles_indir() before executing make sure you don't overwrite the already present file and rename the file with filename1.extension. MoveFile() Should read file in the folder not in sub folders/\*. as soon as it read it moves the file if a file is not presetn there already.
  - [ ] logic for Starting and Stopping as stated under GUI is still left to do

- [ ] Discussion
  - [x] Related to using GUI Framework - GTK was chosen
  - [ ] Use of native APIs for smaller tasks or inclusion of third party cross platform libraries

## Config.conf file

```conf
# Source directories and file extension mappings

# source directory 1
[source_directory_1]
source_directory = /home/user/downloads
images = .png, .jpg, .jpeg, .webp, .gif
documents = .pdf, .txt, .docx
videos = .mp4, .mkv, .avi
music = .mp3, .wav, .flac
others = .zip, .tar.gz, .rar

# source directory 2
[source_directory_2]
source_directory = /home/user/other_downloads
images = .bmp, .svg, .png
documents = .pdf, .txt
audio = .mp3, .ogg
archives = .zip, .tar, .rar

# source directory 3
[source_directory_3]
source_directory = /home/user/media
media = .mp4, .mkv, .avi, .webm
documents = .txt, .pdf, .epub
```
