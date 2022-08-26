
type path = string

module Path = struct
    let to_string p = p
    let from_string s = s
    external exists : path -> bool = "mlcpp_path_exists"
    external file_size : path -> int = "mlcpp_path_file_size"
    external cpp_absolute : path -> path = "mlcpp_path_absolute"
    let absolute p =
        let p' = cpp_absolute p in
        match p' with
        | "" -> None
        | _ -> Some p'
    external cpp_relative : path -> path = "mlcpp_path_relative"
    let relative p =
        let p' = cpp_relative p in
        match p' with
        | "" -> None
        | _ -> Some p'
    external cpp_proximate : path -> path = "mlcpp_path_proximate"
    let proximate p =
        let p' = cpp_proximate p in
        match p' with
        | "" -> None
        | _ -> Some p'
    external cpp_canonical : path -> path = "mlcpp_path_canonical"
    let canonical p =
        let p' = cpp_canonical p in
        match p' with
        | "" -> None
        | _ -> Some p'
    external cpp_weakly_canonical : path -> path = "mlcpp_path_weakly_canonical"
    let weakly_canonical p =
        let p' = cpp_weakly_canonical p in
        match p' with
        | "" -> None
        | _ -> Some p'
    external path_type : path -> string = "mlcpp_path_type"
    external is_regular_file : path -> bool = "mlcpp_path_is_regular_file"
    external is_directory : path -> bool = "mlcpp_path_is_directory"
    external is_fifo : path -> bool = "mlcpp_path_is_fifo"
    external is_block_file : path -> bool = "mlcpp_path_is_block_file"
    external is_character_file : path -> bool = "mlcpp_path_is_character_file"
    external is_socket : path -> bool = "mlcpp_path_is_socket"
    external is_symlink : path -> bool = "mlcpp_path_is_symlink"
    external is_other : path -> bool = "mlcpp_path_is_other"
end (* Path *)

module Permissions = struct
    type permissions = int

    external cpp_get : path -> permissions = "mlcpp_permissions_get"
    let get p =
        let perms = cpp_get p in
        match perms with
        | -1 -> None
        | _ -> Some perms

    external set : path -> permissions -> bool = "mlcpp_permissions_set"
    external add : path -> permissions -> bool = "mlcpp_permissions_add"
    external remove : path -> permissions -> bool = "mlcpp_permissions_remove"
    let to_dec p = p
    let threebits p n = 
        let v = match n with
                | 0 -> p
                | _ -> Int.shift_right_logical p (n * 3)
                in
        Int.logand v 7
    let to_oct p = threebits p 0 + (10 * threebits p 1) + (100 * threebits p 2)
    let pstr o = match o with
        | 0 -> "---"
        | 1 -> "--x"
        | 2 -> "-w-"
        | 4 -> "r--"
        | 3 -> "-wx"
        | 5 -> "r-x"
        | 7 -> "rwx"
        | 6 -> "rw-"
        | _ -> "???"
    let to_string p =
        let o = to_oct p in
        let oth = o - (o / 10) * 10 in
        let grp = (o - (o / 100) * 100) / 10 in
        let usr = (o - (o / 1000) * 1000) / 100 in
        (pstr usr) ^ (pstr grp) ^ (pstr oth)
    let from_oct o =
        let oth = o - (o / 10) * 10 in
        let grp = (o - (o / 100) * 100) / 10 in
        let usr = (o - (o / 1000) * 1000) / 100 in
        oth + grp * 8 + usr * 8 * 8
end (* Permissions *)

external get_cwd : unit -> path = "mlcpp_get_cwd"
external set_cwd : path -> bool = "mlcpp_set_cwd"

external copy : path -> path -> bool = "mlcpp_copy"
external copy_file : path -> path -> bool = "mlcpp_copy_file"
external copy_symlink : path -> path -> bool = "mlcpp_copy_symlink"

external create_directory : path -> bool = "mlcpp_create_directory"
external create_directories : path -> bool = "mlcpp_create_directories"

external create_hard_link : path -> path -> bool = "mlcpp_create_hard_link"
external create_symlink : path -> path -> bool = "mlcpp_create_symlink"
external create_directory_symlink : path -> path -> bool = "mlcpp_create_directory_symlink"

external equivalent : path -> path -> bool = "mlcpp_equivalent"

external hard_link_count : path -> int = "mlcpp_hard_link_count"

external cpp_read_symlink : path -> path = "mlcpp_read_symlink"

let read_symlink p =
    let p' = cpp_read_symlink p in
    match p' with
    | "" -> None
    | _ -> Some p'

external remove : path -> bool = "mlcpp_remove"
external remove_all : path -> int = "mlcpp_remove_all"

external rename : path -> path -> bool = "mlcpp_rename"

external resize_file : path -> int -> bool = "mlcpp_resize_file"

external space : path -> int list = "mlcpp_space"