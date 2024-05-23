open Mlcpp_filesystem

module Testing = struct
  let get = fun sfp -> Filesystem.Permissions.get (Filesystem.Path.from_string sfp)
  let set = fun sfp o -> Filesystem.Permissions.set (Filesystem.Path.from_string sfp) (Filesystem.Permissions.from_oct o)
  let add = fun sfp o -> Filesystem.Permissions.add (Filesystem.Path.from_string sfp) (Filesystem.Permissions.from_oct o)
  let remove = fun sfp o -> Filesystem.Permissions.remove (Filesystem.Path.from_string sfp) (Filesystem.Permissions.from_oct o)
end

(* Tests *)

let test_get_existing () =
  Alcotest.(check int) "permissions of existing file"
  755 (* == *) (match Testing.get "test.exe" with | None -> -1 | Some p -> Filesystem.Permissions.to_oct p)

let test_get_unknown () =
  Alcotest.(check int) "permissions of unknown file"
  (-1) (* == *) (match Testing.get "test134.exe" with | None -> -1 | Some p -> Filesystem.Permissions.to_oct p)

let test_add_existing () =
  Alcotest.(check bool) "add permissions"
  true (* == *) (Testing.add "test.exe" 010)

let test_add_unknown () =
  Alcotest.(check bool) "add permissions fail"
  false (* == *) (Testing.add "test092.exe" 010)

let test_remove_existing () =
  Alcotest.(check bool) "remove permissions"
  true (* == *) (Testing.remove "test.exe" 010)

let test_remove_unknown () =
  Alcotest.(check bool) "remove permissions fail"
  false (* == *) (Testing.remove "test192.exe" 010)

let test_set_existing () =
  Alcotest.(check bool) "set permissions"
  true (* == *) (Testing.set "test.exe" 755)

let test_set_unknown () =
  Alcotest.(check bool) "set permissions fail"
  false (* == *) (Testing.set "test392.exe" 755)



(* Runner *)

let test =
  let open Alcotest in
  "ML Cpp Filesystem.Permissions",
  [
    test_case "get permissions" `Quick test_get_existing;
    test_case "get permissions fail" `Quick test_get_unknown;
    test_case "add permissions" `Quick test_add_existing;
    test_case "add permissions fail" `Quick test_add_unknown;
    test_case "remove permissions" `Quick test_remove_existing;
    test_case "remove permissions fail" `Quick test_remove_unknown;
    test_case "set permissions" `Quick test_set_existing;
    test_case "set permissions fail" `Quick test_set_unknown;
  ]