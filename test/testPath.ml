open Mlcpp_filesystem

module Testing = struct
  let from_string = Filesystem.Path.from_string
  let to_string = Filesystem.Path.to_string
  let exists = fun sfp -> Filesystem.Path.exists @@ Filesystem.Path.from_string sfp
  let file_size = fun sfp -> Filesystem.Path.file_size @@ Filesystem.Path.from_string sfp
  let absolute = fun sfp -> Filesystem.Path.absolute @@ Filesystem.Path.from_string sfp
  let append = fun fp1 fp2 -> Filesystem.Path.append (Filesystem.Path.from_string fp1) (Filesystem.Path.from_string fp2)
  let canonical = fun sfp -> Filesystem.Path.canonical @@ Filesystem.Path.from_string sfp
  let relative = fun sfp -> Filesystem.Path.relative @@ Filesystem.Path.from_string sfp
  let proximate = fun sfp -> Filesystem.Path.proximate @@ Filesystem.Path.from_string sfp
  let weakly_canonical = fun sfp -> Filesystem.Path.weakly_canonical @@ Filesystem.Path.from_string sfp
  let path_type = fun sfp -> Filesystem.Path.path_type @@ Filesystem.Path.from_string sfp
  let is_regular_file = fun sfp -> Filesystem.Path.is_regular_file @@ Filesystem.Path.from_string sfp
  let is_directory = fun sfp -> Filesystem.Path.is_directory @@ Filesystem.Path.from_string sfp
  let is_other = fun sfp -> Filesystem.Path.is_other @@ Filesystem.Path.from_string sfp
  let parent = fun sfp -> Filesystem.Path.parent @@ Filesystem.Path.from_string sfp
end



(* Tests *)

let test_from_string () =
  Alcotest.(check string)
  "path is a string"
  "/tmp/" (* == *) (Filesystem.Path.to_string @@ Testing.from_string "/tmp/")

let test_exists_fail () =
  Alcotest.(check bool)
  "non-existant file"
  false (* == *) (Testing.exists "/tmp/asdlfhuo340939022")
let test_exists_succeed () =
  Alcotest.(check bool)
  "existing file"
  true (* == *) (Testing.exists "test.exe")

let test_file_size () =
  Alcotest.(check bool)
  "file size > 0"
  true (* == *) (0 < Testing.file_size "test.exe")

let test_absolute () =
  Alcotest.(check bool)
  "absolute"
  true (* == *) (match Testing.absolute "." with | Some _p -> true | None -> false)

let test_canonical () =
  Alcotest.(check bool)
  "canonical"
  true (* == *) (match Testing.canonical ".." with | Some _p -> true | None -> false)

let test_weakly_canonical () =
  Alcotest.(check bool)
  "weakly canonical"
  true (* == *) (match Testing.weakly_canonical ".." with | Some _p -> true | None -> false)

let test_relative () =
  Alcotest.(check bool)
  "relative"
  true (* == *) (match Testing.relative ".." with | Some _p -> true | None -> false)

let test_proximate () =
  Alcotest.(check bool)
  "proximate"
  true (* == *) (match Testing.proximate ".." with | Some _p -> true | None -> false)

let test_path_type_dir () =
  Alcotest.(check string)
  "path type directory"
  "directory" (* == *) (Testing.path_type ".")

let test_path_type_file () =
  Alcotest.(check string)
  "path type file"
  "file" (* == *) (Testing.path_type "test.exe")

let test_is_regular_file_fail () =
  Alcotest.(check bool)
  "dir is not a file"
  false (* == *) (Testing.is_regular_file "..")

let test_is_regular_file () =
  Alcotest.(check bool)
  "a file"
  true (* == *) (Testing.is_regular_file "test.exe")

let test_is_directory () =
  Alcotest.(check bool)
  "a directory"
  true (* == *) (Testing.is_directory "..")

let test_is_directory_fail () =
  Alcotest.(check bool)
  "a file is not a dir"
  false (* == *) (Testing.is_directory "test.exe")

let test_is_other_fail () =
  Alcotest.(check bool)
  "a file is not some 'other'"
  false (* == *) (Testing.is_other "test.exe")

let test_path_append () =
  Alcotest.(check string)
  "appending two paths returns a path"
  "/data/dir/file.dat" (* == *) (Testing.append "/data" "/dir/file.dat" |> Testing.to_string)

let test_path_append2 () =
  Alcotest.(check string)
  "appending two paths returns a path"
  "/data/dir/file.dat" (* == *) (Testing.append "/data" "dir/file.dat" |> Testing.to_string)

let test_path_parent () =
  Alcotest.(check string)
  "parent of a path"
  "/data/dir" (* == *) (Testing.parent "/data/dir/file.dat" |> Testing.to_string)

  
(* Runner *)

let test =
  let open Alcotest in
  "ML Cpp Filesystem.Path",
  [
    test_case "String to Filesystem.Path" `Quick test_from_string;
    test_case "non-existant file" `Quick test_exists_fail;
    test_case "existing file" `Quick test_exists_succeed;
    test_case "File size > 0" `Quick test_file_size;
    test_case "absolute path" `Quick test_absolute;
    test_case "canonical path" `Quick test_canonical;
    test_case "weakly canonical path" `Quick test_weakly_canonical;
    test_case "relative path" `Quick test_relative;
    test_case "proximate path" `Quick test_proximate;
    test_case "path type dir" `Quick test_path_type_dir;
    test_case "path type file" `Quick test_path_type_file;
    test_case "a file" `Quick test_is_regular_file;
    test_case "not a file" `Quick test_is_regular_file_fail;
    test_case "a dir" `Quick test_is_directory;
    test_case "not a dir" `Quick test_is_directory_fail;
    test_case "not some other" `Quick test_is_other_fail;
    test_case "appending absolut paths" `Quick test_path_append;
    test_case "appending relative path" `Quick test_path_append;
    test_case "parent of path" `Quick test_path_parent;
  ]