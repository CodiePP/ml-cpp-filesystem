# ml-cpp-filesystem
OCaml embedded cross-platform C++ &lt;[filesystem](https://en.cppreference.com/w/cpp/filesystem)>

the interface:
```OCaml

type path

module Path :
sig
    val to_string : path -> string
    val from_string : string -> path

    val temp_directory : unit -> path

    val exists : path -> bool
    
    val file_size : path -> int

    val filename : path -> path
    val extension : path -> path
    val parent : path -> path
    val root : path -> path
    
    val absolute : path -> path option
    val relative : path -> path option
    val proximate : path -> path option
    val canonical : path -> path option
    val weakly_canonical : path -> path option

    val path_type : path -> string
    val is_regular_file : path -> bool
    val is_directory : path -> bool
    val is_fifo : path -> bool
    val is_block_file : path -> bool
    val is_character_file : path -> bool
    val is_socket : path -> bool
    val is_symlink : path -> bool
    val is_other : path -> bool
end

module Permissions :
sig
    type permissions
    val get : path -> permissions option
    val set : path -> permissions -> bool
    val add : path -> permissions -> bool
    val remove : path -> permissions -> bool
    val to_string : permissions -> string
    val to_dec : permissions -> int
    val to_oct : permissions -> int
    val from_oct : int -> permissions
end

val get_cwd : unit -> path
val set_cwd : path -> bool

val copy : path -> path -> bool
val copy_file : path -> path -> bool
val copy_symlink : path -> path -> bool

val create_directory : path -> bool
val create_directories : path -> bool

val create_hard_link : path -> path -> bool
val create_symlink : path -> path -> bool
val create_directory_symlink : path -> path -> bool

val equivalent : path -> path -> bool

val hard_link_count : path -> int

val read_symlink : path -> path option

val remove : path -> bool
val remove_all : path -> int

val rename : path -> path -> bool

val resize_file : path -> int -> bool

val space : path -> int list

```
